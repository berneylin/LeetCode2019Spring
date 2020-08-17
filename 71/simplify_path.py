class Solution:
    def simplifyPath(self, path: str) -> str:
        path_split = path.split('/')
        stack = []
        for sub_path in path_split:
            if sub_path == '.':
                continue
            elif sub_path == '..':
                if len(stack) != 0:
                    stack.pop()
            elif sub_path:
                stack.append(sub_path)

        return '/' + '/'.join(stack)
