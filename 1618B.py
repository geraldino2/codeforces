___ = int(input())
for __ in range(___):
	n = int(input())
	seq = ""
	biagrams = input().split()
	lastletter = ""
	for biagram in biagrams:
		if(biagram[0]==lastletter):
			seq += biagram[1]
		else:
			seq += biagram[0:2]
		lastletter = biagram[-1]
	if(len(seq)<n):
		seq+=seq[-1]*(n-len(seq))
	print(seq)
