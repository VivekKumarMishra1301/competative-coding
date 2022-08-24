def solve(ip,op,ind):
    if ind==len(ip):
        
        ans.append(''.join(op))
        # print(repr(op).replace(' ', ''),end=","
        return
    if ip[ind].isdigit():
        op.append(ip[ind])
        solve(ip,op,ind+1)
        op.pop()
    else:
        op.append(ip[ind])
        solve(ip,op,ind+1)
        op.pop()
        op.append(ip[ind].upper())
        solve(ip,op,ind+1)
        op=op.pop()
    
    
    
ind=0
ip=input() 

ans=[]
op=[]
solve(list(ip),op,0) 
print(str(ans).replace(' ',''))
    