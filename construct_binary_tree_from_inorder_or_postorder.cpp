void createmapping(int in[], map<int,int> &nodeToIndex, int n){
    for(int i = 0; i<n; i++){
        nodeToIndex[in[i]] = i;
    }
}
Node *solve(int in[], int post[], int &index, int inorderstart, int inorderend, int n, map<int,int> &nodeToIndex){
    if(index < 0 || inorderstart > inorderend){
        return NULL;
    }
    int element = post[index--];
    Node* root  = new Node(element);

    int position = nodeToIndex[element];

    root->left = solve(in,post,index,inorderstart,position-1,n,nodeToIndex);
    root->right = solve(in,post,index,position+1,inorderend,n,nodeToIndex);
    return root;
}
Node* buildtree(int in[], int pre[], int n){
    int postorderindex = n-1;
    map<int,int> nodetoindex;
    createmapping(in, nodetoindex, n);
    Node* ans = solve(in,post,postorderindex,0,n-1,n,nodetoindex);
    return ans;
}
