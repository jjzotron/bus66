from __future__ import print_function
import itertools

def rotations(lnu):
	''' [1, 2, 3] -> [[1, 2, 3], [2, 3, 1], [3, 1 2]] '''
	rotations = []
	repeat_lnu = lnu * 3 # instead of rotating string, just index later in a repeat
	for x in range(len(lnu)):
		rotations.append(repeat_lnu[x:len(lnu)+x])
	return rotations
	
def rotate_extend(lnu):
	return [x + x[:-1] for x in lnu]
	
def permutation_rows(n):
	''' returns list of permutations up to n [1, 2, ..., n] that start with 1 '''
	rows = []
	# get all permutations of n that start with '1'
	# e.g. n = 3 -> [1, 2, 3], [1, 3, 2]
	for x in itertools.permutations(range(2, n+1)): # permutes [2, 3, 4]
		rows.append([1] + list(x))
	return rows
	
def rotation_table(n):
	''' get a table like this: (n=4)
	[[1, 2, 3, 4], [2, 3, 4, 1], [3, 4, 1, 2], [4, 1, 2, 3]]
	[[1, 2, 4, 3], [2, 4, 3, 1], [4, 3, 1, 2], [3, 1, 2, 4]]
	[[1, 3, 2, 4], [3, 2, 4, 1], [2, 4, 1, 3], [4, 1, 3, 2]]
	[[1, 3, 4, 2], [3, 4, 2, 1], [4, 2, 1, 3], [2, 1, 3, 4]]
	[[1, 4, 2, 3], [4, 2, 3, 1], [2, 3, 1, 4], [3, 1, 4, 2]]
	[[1, 4, 3, 2], [4, 3, 2, 1], [3, 2, 1, 4], [2, 1, 4, 3]]
	where each row has a permutation that starts with '1'
	and each column contains a rotated version of the row "123" -> "231"
	'''
	# [rotations(x) for x in permutation_rows(n)]
	rot_table = []
	for row in permutation_rows(n):
		rot_table.append(rotate_extend(rotations(row)))
		'''
		new_row = []
		for item in rotations(row):
			new_row.append(row + row[:-1])
		rot_table.append(new_row)'''
	return rot_table	

def overlap(list_a, list_b):
	''' how many numbers at the start of list_b overlap onto the end of list_a 
	e.g. [1, 2, 3], [2, 3, 4] -> 2 '''
	assert(len(list_a) == len(list_b))
	overlap = 0
	for index in range(len(list_a)):
		if list_a[index:] == list_b[:len(list_b)-index]:
			overlap = len(list_b) - index
	return overlap

def sanity_checks():
	print("overlap() test: ", overlap([1, 2, 3, 4, 5], [4, 5, 1, 2, 3]) == 2)
	print("overlap() test: ", overlap([1, 2, 3, 4, 5], [5, 4, 1, 2, 3]) == 1)
	print("overlap() test: ", overlap([1, 1, 1], [2, 2, 2]) == 0)
	print("overlap() test: ", overlap([4, 5, 1, 2, 3], [4, 5, 1, 2, 3]) == 5)
	
def find_best_match(lnu, table):
	''' return the table entry with the most overlap for given list '''
	best_match = 0, 0, 0 # over, row, col
	for y, row in enumerate(table):
		for x, col in enumerate(row):
			over = overlap(lnu, col)
			if over > best_match[0]:
				best_match = over, y, x
	return best_match

def print_table(table):
	for row in table:
		print(row)
		
		
def main():
	INPUT_N = 4
	table = rotation_table(INPUT_N)
	num_rows = len(table) - 1
	current_perm = table.pop(0)[0] # first element of table is [1, 2, ..., n]
	superperm = current_perm[:] # copy all initial digits 
		
	for x in range(num_rows): # -2, one for starting val, one for off-by-one
		#print_table(table)		
		# find the best match (overlap, row, column) in the rotation table 
		over, row, col = best_match = find_best_match(current_perm, table) 
		value = table[row][col]
		superperm.extend(value[over:]) # add it to the superperm	
		current_perm = value # set current permutation to the one just found
		table.pop(row) # delete row current perm was found in
		
	length = len(superperm)
	print(length, ''.join(map(str, superperm)))
	
		
if __name__ == '__main__':
	main()

