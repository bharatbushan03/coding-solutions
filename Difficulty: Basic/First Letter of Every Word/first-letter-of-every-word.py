class Solution:
	def firstAlphabet(self, s):
		return ''.join(c[0] for c in s.split())