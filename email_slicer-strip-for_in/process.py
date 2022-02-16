def processEmail(email):
    # thinhitnguyenvan@gmail.com
    username = email[0:email.index('@')]  # thinhitnguyenvan
    domain = email[email.index('@') + 1:]  # @gmail.com
    return [username, domain]


def printResult(username, domain):
    print(f"Username is {username}")
    print(f"Domain is {domain}\n")


def main():
    # Remove spaces at the beginning and at the end of input
    email = input("Enter your email: ").strip()
    username, domain = processEmail(email)
    printResult(username, domain)


if __name__ == "__main__":
    main()
