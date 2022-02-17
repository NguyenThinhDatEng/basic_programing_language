def C_to_F(cTemp):
    return round(9 * cTemp / 5 + 32, 1)


def printResult(cTemp, fTemp):
    print(f'{cTemp}°C = {fTemp}°F')


def main():
    cTemp = input('Enter C degree: ')
    printResult(cTemp, C_to_F(float(cTemp)))


if __name__ == '__main__':
    main()
