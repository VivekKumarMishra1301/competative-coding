class BrowserHistory {
public:
   stack<string>hist;
    stack<string>forw;
    BrowserHistory(string homepage) {
      hist.push(homepage);
    }
    
    void visit(string url) {
      while(!forw.empty()){
          // hist.push(forw.top());
          forw.pop();
      }
         hist.push(url);
   
        }
    
    string back(int steps) {
        
        while(steps--){
            
       if(hist.size()>1){
           string top=hist.top();
           forw.push(top);
           hist.pop();
       }else{
           break;
       }
        }
        return hist.top();
    }
    
    string forward(int steps) {
       while(steps--){
           if(!forw.empty()){
               string top=forw.top();
               hist.push(top);
               forw.pop();
           }else{
               break;
           }
       }
        return hist.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */