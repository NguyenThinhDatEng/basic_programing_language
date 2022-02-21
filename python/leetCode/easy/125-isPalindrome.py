s = "A man, a plan, a canal: Panama"

def isPalindrome(s):
    characters = []
    s = s.lower()
    for c in s:
        if c.isalnum():
            characters.append(c)
    print(characters)
    return characters == list(reversed(characters))

def main():
    print(isPalindrome(s))

main()