function cor(input){
    let obj={};
for(let i=0;i<input.length;i++){
    if(input[i] in obj){
        obj[input[i]]=obj[input[i]]+1;
    }else{
        obj[input[i]]=0;
    }
}

let prev=0;
let curr=0;
for(let key in obj){
    prev=curr;
    curr=obj[key];
}

let res=parseInt(input.length)-parseInt(prev)-parseInt(curr);
return res;
}

