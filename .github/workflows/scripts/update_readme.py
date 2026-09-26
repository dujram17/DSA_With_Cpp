import os
import re
import requests
from collections import defaultdict

README_FILE = "README.md"

LEETCODE_API = "https://leetcode.com/graphql"

QUERY = """
query questionData($titleSlug: String!) {
  question(titleSlug: $titleSlug) {
    questionFrontendId
    title
    difficulty
    titleSlug
    topicTags {
      name
    }
  }
}
"""

def get_questions():
    questions = []

    for item in os.listdir("."):
        if not os.path.isdir(item):
            continue

        # Example: 54-spiral-matrix
        match = re.match(r"^(\d+)-(.+)$", item)

        if not match:
            continue

        number = match.group(1)
        slug = match.group(2)

        try:
            response = requests.post(
                LEETCODE_API,
                json={
                    "query": QUERY,
                    "variables": {"titleSlug": slug}
                },
                timeout=15
            )

            data = response.json()
            question = data.get("data", {}).get("question")

            if not question:
                print(f"Could not find: {item}")
                continue

            questions.append({
                "number": number,
                "title": question["title"],
                "difficulty": question["difficulty"],
                "topics": question["topicTags"],
                "folder": item
            })

            print(f"Found: {item}")

        except Exception as e:
            print(f"Error with {item}: {e}")

    return questions


def create_readme(questions):
    topics = defaultdict(list)

    for question in questions:
        for topic in question["topics"]:
            topics[topic["name"]].append(question)

    content = """# DSA With C++

A collection of my Data Structures and Algorithms learning, practice, and problem-solving journey using C++.

## LeetCode Problems

"""

    # Sort topics alphabetically
    for topic in sorted(topics):
        content += f"## {topic}\n\n"

        content += "| Problem Name | Difficulty |\n"
        content += "|---|---|\n"

        # Sort questions by problem number
        topic_questions = sorted(
            topics[topic],
            key=lambda x: int(x["number"])
        )

        for question in topic_questions:
            folder = question["folder"]
            title = f'{question["number"]}-{question["title"]}'

            link = f"./{folder}"

            content += (
                f"| [{title}]({link}) "
                f"| {question['difficulty']} |\n"
            )

        content += "\n"

    # Remove duplicate problems appearing in multiple topics
    unique_questions = {
        q["folder"]: q for q in questions
    }

    content += "## Progress\n\n"
    content += f"**Total Problems Solved: {len(unique_questions)}**\n"

    return content


def main():
    print("Updating README...")

    questions = get_questions()

    if not questions:
        print("No LeetCode problems found.")
        return

    readme = create_readme(questions)

    with open(README_FILE, "w", encoding="utf-8") as file:
        file.write(readme)

    print("README updated successfully!")


if __name__ == "__main__":
    main()
