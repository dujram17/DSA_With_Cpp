import os
import re
import requests
from collections import defaultdict

README_FILE = "README.md"

QUERY = """
query questionData($titleSlug: String!) {
  question(titleSlug: $titleSlug) {
    questionFrontendId
    title
    difficulty
    topicTags {
      name
    }
  }
}
"""

def get_question(slug):
    response = requests.post(
        "https://leetcode.com/graphql",
        json={
            "query": QUERY,
            "variables": {"titleSlug": slug}
        },
        headers={
            "User-Agent": "Mozilla/5.0"
        },
        timeout=20
    )

    data = response.json()
    return data.get("data", {}).get("question")


def main():

    topics = defaultdict(list)
    solved = {}

    for folder in os.listdir("."):

        if not os.path.isdir(folder):
            continue

        # Example:
        # 54-spiral-matrix
        # 1677-matrix-diagonal-sum
        match = re.match(r"^(\d+)-(.+)$", folder)

        if not match:
            continue

        number = match.group(1)
        slug = match.group(2)

        print("Checking:", folder)

        try:
            question = get_question(slug)

            if not question:
                print("Not found:", folder)
                continue

            solved[folder] = question

            for topic in question["topicTags"]:
                topics[topic["name"]].append(
                    {
                        "number": number,
                        "title": question["title"],
                        "difficulty": question["difficulty"],
                        "folder": folder
                    }
                )

        except Exception as e:
            print("Error:", folder, e)

    # README content
    readme = """# DSA With C++

A collection of my Data Structures and Algorithms learning, practice, and problem-solving journey using C++.

## LeetCode Problems

"""

    # Topic-wise tables
    for topic in sorted(topics):

        readme += f"## {topic}\n\n"

        readme += "| Problem Name | Difficulty |\n"
        readme += "|---|---|\n"

        questions = sorted(
            topics[topic],
            key=lambda x: int(x["number"])
        )

        for q in questions:

            link = f"./{q['folder']}"

            readme += (
                f"| [{q['number']}-{q['title']}]({link}) "
                f"| {q['difficulty']} |\n"
            )

        readme += "\n"

    # Progress
    readme += "## Progress\n\n"
    readme += f"**Total Problems Solved: {len(solved)}**\n"

    with open(README_FILE, "w", encoding="utf-8") as file:
        file.write(readme)

    print("README updated successfully!")


if __name__ == "__main__":
    main()
