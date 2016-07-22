using namespace std;

class heapminmax
{

public:
	heapminmax();
	~heapminmax();

	struct no
	{
		no *pai;
		int valor;
	};

	no *raiz;
	int n=0;

	int avo(int i){
		int avo;
		return avo;
	}

	int pai(int i){
		int pai;
		return pai;
	}

	void remover(int[] v, int i){
		int m = menorFilhosNetos(i);
		int avo = avo(m);
		int aux;
		if (avo == i){
			if(v[i]>v[m]){
				aux   = v[i];
				v[i]  = v[m];
				v[m]  = aux;
				int p = pai(i);
				if(v[m]>v[p]){
					aux  = v[m];
					v[m] = v[p];
					v[p] = aux;
				}
				descermim(v,m);
			}
		}
		else if(v[i]>v[m]){
			aux  = v[i];
			v[i] = v[m];
			v[m] = aux;
		}
	}

	int menorFilhosNetos(int[] v, int i){
		int menor = v[0];
		int m;
		for (int j = 4*i; j < 4*i +3; j++)
		{
			if(v[j]<menor){
				menor = v[j];
				m = j;
			}
		}
		for (int j = 2*i; j < 2*i +1; j++)
		{
			if (v[j] < menor) {
				menor = v[j];
				m = j;
			}
		}
		return m
	}

	int nivel(int i){
		int nivel;
		return nivel;
	}

	void subirmin(int[] v, int i){
		int a = avo(i);
		int aux;
		if(a>=1 && nivel(a)%2==1){
			if(v[i]<v[a]){
				aux  = v[i];
				v[i] = v[a];
				v[a] = aux;
				subirmin(v,a);
			}
		}
	}

	void subirmax(int [v], int i){
		int a = avo(i);
		int aux;
		if(a>=2 && nivel(a)%2==0){
			if(v[i]>v[a]){
				aux  = v[i];
				v[i] = v[a];
				v[a] = aux;
				subirmax(v,a);
			}
		}
	}

	void subir(int[] v, int i){
		int p = pai(i);
		int aux;
		if(p>=1)
		{
			if(nivel(p)%2==1){
				if(v[p]>=v[i]){
					aux  = v[p];
					v[p] = v[i];
					v[i] = aux;
				}
				else{
					subirmin(v,p);
					subirmax(v,i);
				}
			}
			else{
				if(v[p]<=v[i]){
					aux  = v[p];
					v[p] = v[i];
					v[i] = aux;
					subirmax(v,p);
				}
				else
					subirmin(v,i)
			}
		}
	}

	void inserir(int[] v){
		n=n+1;
		v[n] = x;
		subir(v,n);
	}

	void removermin(int[] v){
		v[1]=v[n];
		n = n-1;
		descermim(v,1);
	}

	void removermax(int[] v){
		int j = v[2]>v[3] ? 2:3;
		v[j] = v[n];
		n = n-1;
		descermax(v,j);
	}

	void alterar(int[] v, i, x){
		int p;
		int aux;
		if(v[i]==x)
			return 0;
		anterior = v[i];
		v[i] = x;
		else if(nivel(i)%2==1){
			if(x>v[i]){
				p = pai(i);
				if(p>=1 && v[p]<v[i]){
					aux  = v[i];
					v[i] = v[p];
					v[p] = aux;
					subir(p);
				}
				else
					subir(i);
			}
		}
		else{
			if(v[i]<anterior){
				p = pai(i);
				if(p>=1 && v[p]>v[i]){
					aux  = v[i];
					v[i] = v[p];
					v[p] = aux;
					subir(p);
				}
			}
		}

	}
};