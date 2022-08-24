# def solve(ip,op,ind):
#     if len(ip)==ind:
        
#         opt.append(op.copy())
#         # print(repr(op).replace(' ', ''),end=",")

#         return
   
#     solve(ip,op,ind+1)
#     op.append(ip[ind])
   
#     solve(ip,op,ind+1)
#     op.pop()
    
# ind=0
# ip=[]
# inp=int(input())
# for i in range(0,inp):
#     q=int(input())
    
#     ip.append(q)
# opt=[]   
# op=[]   
# solve(ip,op,ind)
# print(repr(opt).replace(' ', ''))
    

# a="vivek"

# print(a)
# a.pop()
# print(a)
def solve(s,d):
    if s==d:
        return
    for i in range(s,d+1):
        print(i,end="")
        solve(s+1,d)

solve(1,3)