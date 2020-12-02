// Exam 3 Part 2 Answers by Knox Crichton
// Question 11 A
node* minkey(node* n){
	if(n == NULL){
		return NULL;
	}
	node* temp =n;
	while(temp->left != NULL){
		temp=temp->left;
	}
	return temp;
}
// Question 11 B
node* minkey(node* n){
	if(n==NULL){
		return NULL;
	}
	if(n->left==NULL){
		return n;
	}else{
		return minkey(n->left);
	}
}

// Question 12 A

node* find(node* n, int k){
	while(n!=NULL){

		if(k > n->key){
			n = n->right;
		}else if(k < n->key){
			n = n->left;
		}else{
			return n;
		}
	}
	return NULL;
}
// Question 12 B
node* find(node* n, int k){
	if(n == NULL || n->key = k){
		return n;
	}
	if(n->key < key){
		return find(n->right, k);
	}
	return find(n->left, k);
}

// Question 13
insert(node* r, int k){
	if(r == NULL){
		r = new node(k,1);
	}else if(r->key == k){
		r->count++;
	}else if(r->key > k){
		r->left = insert(r->left,k);
	}else{
		r->right = insert(r->right, k);
	}
	return r;
}


