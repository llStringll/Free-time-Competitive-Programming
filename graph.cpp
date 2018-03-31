#include<bits/stdc++.h>

using namespace std;

struct vertex{
	int data;
	bool visited;
	vector <struct vertex *> edges;
};

struct graph{
	vector <struct vertex *> vertices;
};

void add(graph *g,vertex *v){
	g->vertices.push_back(v);
}

void join(vertex *va,vertex *vb){
	va->edges.push_back(vb);
	vb->edges.push_back(va);
}

void showedges(vertex *v){

	for(int i=0;i<v->edges.size();i++)
		cout<<v->edges[i]->data<<" ";
	cout<<"\n";
}

void dfs(struct vertex *v){
	v->visited=true;
	cout<<v->data;

	for(int i=0;i<v->edges.size();i++){
		if(v->edges[i]->visited!=true)dfs(v->edges[i]);
	}
}

void bfs(struct vertex *v){
	v->visited=true;
	cout<<v->data;

	
}

int main(){
	graph *g1 = new graph;

	vertex *v1=new vertex;
	v1->data=1;
	vertex *v2=new vertex;
	v2->data=2;
	vertex *v3=new vertex;
	v3->data=3;
	vertex *v4=new vertex;
	v4->data=4;
	vertex *v0=new vertex;
	v0->data=0;

	add(g1,v1);
	add(g1,v2);
	add(g1,v3);
	add(g1,v4);
	add(g1,v0);

	join(v1,v2);
	join(v1,v0);
	join(v0,v2);
	join(v0,v3);
	join(v4,v2);

	for(int i=0;i<g1->vertices.size();i++){
		cout<<g1->vertices[i]->data<<"---";
		showedges(g1->vertices[i]);
	}

	cout<<"dfs: ";
	dfs(g1->vertices[4]);

	for(int i=0;i<g1->vertices.size();i++){
		g1->vertices[i]->visited=false;
	}

	cout<<"\nbfs: ";
	bfs(g1->vertices[4]);

	return 0;
}