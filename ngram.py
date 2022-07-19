# Simple brute force implementation 
# to get n-grams from given sentence
def ngram(s,t):
    p = s.split()
    c=[]
    for i in range(len(p)-t+1):
        c.append(p[i:i+t])
    return c

print(ngram('Shiv Pratap Singh',2))