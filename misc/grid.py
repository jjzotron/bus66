import itertools
from PIL import Image

def contains_range(lst, n):
    ''' returns true if lst contains all elements 1, 2, ..., n '''
    # valid lists can only contain numbers 1, 2, ..., n
    assert(int(sorted(lst)[-1]) <= n and int(sorted(lst)[0]) >= 1)
    return len(set(lst[len(lst)-n:])) == n

def main():
    superperm = '123121321'
    n = int(sorted(superperm)[-1]) # get biggest elem to find order
    #superperm.trim()
    perms = [''.join(map(str, p)) for p in itertools.permutations(range(1,n+1))]
    #print(len(perms), perms)

    
    adjacency_matrix = [[0]*len(perms) for x in range(len(perms))] # make a permsXperms adjacency matrix
    #print(adjacency_matrix)
    substrings = len(superperm) - n # num of substrings length n
    last = superperm[0:n]
    color = (0, 0, 0)
    for i in range(substrings+1):
        sp = superperm[i:i+n]
        #print(sp, contains_range(sp, n))
        if contains_range(sp, n):
            print("from:", last, "to:", sp)
            #print(perms.index(last), perms.index(sp))
            adjacency_matrix[perms.index(sp)][perms.index(last)] = color
            color = (color[0] + 1, color[1] + 1, color[2] + 1)
            last = sp


    im = Image.new("RGB", (len(perms), len(perms)), "white")
    
    for x in range(len(adjacency_matrix)):
        for y in range(len(adjacency_matrix)):
            #print(adjacency_matrix[x][y])
            if adjacency_matrix[x][y] != 0:
                im.putpixel((x,y), adjacency_matrix[x][y])
                #c = (30, 50, 50)
                #if c[0] >= 255: c = (0, 255, 0)
                #if c[1] >= 255: c = (0, 0, 255)
                #black = (black[0]+c[0], black[1]+c[1], black[2]+c[2])
    im.show()
    

if __name__ == '__main__':
    main()


