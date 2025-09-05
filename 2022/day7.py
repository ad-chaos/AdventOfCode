from typing import Dict, Self
from functools import cached_property


class TopLevel:
    pass


class Directory:
    def __init__(
        self,
        parent: Self | TopLevel,
        name: str,
        files: list[tuple[int, str]],
        directories: Dict[str, Self],
    ) -> None:
        self.parent = parent
        self.name = name
        self.files = files
        self.directories = directories

    def recurse_dirs(self):
        for folder in self.directories.values():
            yield folder
            for sub_folder in folder.recurse_dirs():
                yield sub_folder

    # NOTE: This is the crux of this whole operation of flattening a tree of
    # sizes into a list, you could do all this recursion yourself by
    # maintaining your own stack and have a lot less amount of code, but well
    # this realisation came afterwards
    @cached_property
    def size(self) -> int:
        final_size = 0

        for file_size, _ in self.files:
            final_size += file_size

        for folder in self.directories.values():
            final_size += folder.size
        return final_size


filesystem = Directory(name="filesystem", parent=TopLevel(), files=[], directories={})
filesystem.directories["/"] = Directory(
    parent=filesystem, name="/", files=[], directories={}
)

cwd = filesystem

with open("./input7.txt") as f:
    while line := f.readline().rstrip():
        if line.startswith("$ "):
            if (line := line[2:]).startswith("cd"):
                _, directory = line.split()

                if directory == "..":
                    assert not isinstance(
                        cwd.parent, TopLevel
                    ), "Can't access the world outside mate"
                    cwd = cwd.parent
                    continue

                cwd = cwd.directories[directory]
            continue

        size, file_or_dir = line.split()
        if size.isnumeric():
            cwd.files.append((int(size), file_or_dir))
        else:
            cwd.directories[file_or_dir] = Directory(
                parent=cwd, name=file_or_dir, files=[], directories={}
            )


def part_1(folder: Directory, bound: int) -> int:
    answer = 0
    for sub_folder in folder.recurse_dirs():
        size = sub_folder.size
        if size <= bound:
            answer += size
    return answer


def part_2(folder: Directory, bound: int) -> list[int]:
    answer = []
    for sub_folder in folder.recurse_dirs():
        size = sub_folder.size
        if size >= bound:
            answer.append(size)
    return answer


print(min(part_2(filesystem, -40000000 + filesystem.size)))
print(part_1(filesystem, 100000))
