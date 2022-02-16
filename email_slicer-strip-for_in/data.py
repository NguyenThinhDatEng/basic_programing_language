from process import processEmail, printResult


def main():
    emails = ['thinhitnguyenvan@gmail.com',
              'toithienamxinnghe@gmail.com', 'thinh.nv194178@sis.hust.edu.vn']
    for email in emails:
        username, domain = processEmail(email)
        printResult(username, domain)


if __name__ == '__main__':
    main()
