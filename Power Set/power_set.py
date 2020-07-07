# it also take care of repeatation of subset
# generate all possible subset of given set
from itertools import combinations
def pow_set(l):
    powerset=[]
    for i in range(len(l)+1):
        for tup in combinations(l,i):
            if tup not in powerset:
                powerset.append(tup)
                print(''.join(tup))
pow_set(['a','b','c'])
