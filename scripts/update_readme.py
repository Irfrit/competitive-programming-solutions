#!/usr/bin/env python3
"""
Syncs solution statistics and repository index with README.md.
"""

from pathlib import Path
import re

ROOT_DIR = Path(__file__).resolve().parent.parent
README_PATH = ROOT_DIR / "README.md"

PLATFORMS = [
    ("AtCoder", "atcoder", "https://atcoder.jp"),
    ("Codeforces", "CodeForces", "https://codeforces.com"),
    ("CSES", "CSES", "https://cses.fi/problemset/"),
    ("USACO", "USACO", "http://www.usaco.org"),
    ("Roadmap / Basics", "AlgorithmRoadmap", ""),
]

def scan_solutions():
    data = {}
    for label, folder, link in PLATFORMS:
        p = ROOT_DIR / folder
        if p.exists():
            cpp_files = sorted(p.rglob("*.cpp"))
            data[label] = {
                "folder": folder,
                "link": link,
                "count": len(cpp_files),
                "files": cpp_files
            }
        else:
            data[label] = {"folder": folder, "link": link, "count": 0, "files": []}
    return data

def generate_table(data):
    total = sum(d["count"] for d in data.values())
    lines = [
        "| Platform | Directory | Solved | Link |",
        "| :--- | :--- | :---: | :--- |",
    ]
    for label, info in data.items():
        name_md = f"**{label}**"
        dir_md = f"[`{info['folder']}/`]({info['folder']}/)"
        count_md = f"`{info['count']}`"
        link_md = f"[Website]({info['link']})" if info["link"] else "-"
        lines.append(f"| {name_md} | {dir_md} | {count_md} | {link_md} |")
    lines.append(f"| **Total** | | **`{total}`** | |")
    return "\n".join(lines), total

def update_readme():
    data = scan_solutions()
    table_md, total = generate_table(data)

    if not README_PATH.exists():
        return

    content = README_PATH.read_text()

    # Replace total in badge
    content = re.sub(
        r"!\[Solutions\]\(https://img\.shields\.io/badge/Solutions-\d+-[^)]+\)",
        f"![Solutions](https://img.shields.io/badge/Solutions-{total}-blue.svg?style=flat-square)",
        content
    )

    # Replace table between markers
    pattern = r"(<!-- STATS_TABLE_START -->)(.*?)(<!-- STATS_TABLE_END -->)"
    replacement = f"\\1\n{table_md}\n\\3"
    new_content = re.sub(pattern, replacement, content, flags=re.DOTALL)

    README_PATH.write_text(new_content)
    print(f"Updated README.md: {total} total solutions tracked.")

if __name__ == "__main__":
    update_readme()
