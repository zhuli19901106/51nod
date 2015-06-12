import re

def main():
	MOD = 10 ** 9 + 7
	n = int(raw_input())
	print((pow(3, n + 1, MOD) - 1) * ((MOD + 1) / 2) % MOD)

if __name__ == '__main__':
	main()
