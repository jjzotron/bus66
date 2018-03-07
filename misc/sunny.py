from __future__ import print_function
import itertools
import random

def verify_superperm(n, sp):
	unfound = []
	for perm in itertools.permutations(range(1, n+1)):
		perm_str = ''.join(map(str, perm))
		if sp.find(perm_str) == -1:
			#print("could not find " + perm_str + " in " + sp)
			unfound.append(perm_str)
		else:
			pass
			#print("found " + perm_str + " in " + sp)
	return unfound

def missing(l, n):
	''' given a list of [1, 2, ..., n], find all missing numbers '''
	missing = []
	for x in range(1, n+1):
		if str(x) not in l:
			missing.append(x)
	return missing
	
def missing_sanity_check():
	assert(missing([1, 2], 3) == [3])
	assert(missing([1, 2], 2) == [])
	assert(missing([1, 2, 4, 5], 5) == [3])
	assert(missing([], 2) == [1, 2])


def find_super(seed, seed_len, running):
	global found_perm
	digits_to_find = 1
	decisions = 0
	
	while(running):	
		m = [] # a list of perms to try at end
		tmp = ""
	
		found_something = False
		#print(seed)
		end_index = seed_len - digits_to_find # index of first number in current permutation
		end_numbers = seed[-end_index:] # get that permutation
		# actually need to find a non-existing m, and if none, then increase the digits
		m = missing(end_numbers, seed_len) # find the missing number
		

		items = [x for x in itertools.permutations(m)]
		random.shuffle(items)
		for p in items: # actually need to pick every subpermutation here.
			x = ''.join([str(j) for j in p])
			decisions = decisions + len(items) - 1
			#print(x)
			#if(len(missing) > 1):
			#print("missing:", m, " - chose", x)
			tmp = end_numbers + str(x)

			if(tmp not in seed):
				#find_super(seed + str(x), seed_len, running)
				seed = seed + str(x)
				found_something = True
				digits_to_find = 1
				break
		
		if not found_something:
			digits_to_find = digits_to_find + 1

		m = []
		tmp = ""		
		if(verify_superperm(seed_len, seed) == []):
			#print("found superperm: ", str(len(seed)), ", - ", seed)
			#print("decisions:", decisions)
			return (len(seed), seed)
	
def main():
	#missing_sanity_check()
	seed = "123456"
	seed_len = len(seed)
	shortest = ""
	while(True):
		curr = find_super(seed, seed_len, True)
		if curr < shortest or shortest == "":
			shortest = curr
			print("new shortest:", shortest)
			
	#print(shortest)
	
if __name__ == "__main__":
	main()