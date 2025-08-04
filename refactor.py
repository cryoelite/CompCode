import os
import re

def get_relative_path(file_path):
    depth = file_path.count('/') -1
    if "msvc" in file_path:
        depth = file_path.count('/') - 2

    return "../" * depth + "Helpers/common.h"

def refactor_file(file_path):
    with open(file_path, 'r') as f:
        content = f.read()

    if "Helpers/common.h" in content:
        print(f"Skipping already refactored file: {file_path}")
        return

    start_tokens = [r"\/\/.*Local Mode", r"#pragma region Headers", r"\/\/.*Headers"]
    end_tokens = [r"#pragma endregion", r"using vs = std::vector<std::string_view>;"]

    start_index = -1
    for token in start_tokens:
        match = re.search(token, content)
        if match:
            start_index = match.start()
            break

    if start_index == -1:
        print(f"Could not find start token in {file_path}")
        return

    end_index = -1
    for token in end_tokens:
        # Find the last occurrence of the token
        match = list(re.finditer(token, content))
        if match:
            end_index = match[-1].end()
            break

    if end_index == -1:
        print(f"Could not find end token in {file_path}")
        return


    relative_path = get_relative_path(file_path)

    replacement_string = f'#include "{relative_path}"'

    new_content = content[:start_index] + replacement_string + content[end_index:]

    with open(file_path, 'w') as f:
        f.write(new_content)
    print(f"Refactored {file_path}")

if __name__ == "__main__":
    for root, dirs, files in os.walk("Problems"):
        for file in files:
            if file.endswith(".cpp"):
                refactor_file(os.path.join(root, file))
