def solve(ip,op,ind):
    if len(ip)==ind:
        
        ans.append(op.copy())
        # print(repr(op).replace(' ', ''),end=","
        return
   
    solve(ip,op,ind+1)
    op.append(ip[ind])
    solve(ip,op,ind+1)
    op.pop() 
    
ind=0
n=int(input()) 
ip=list(map(int,input().split()))
ans=[]
op=[]
solve(ip,op,ind) 
print(str(ans).replace(' ',''))
    