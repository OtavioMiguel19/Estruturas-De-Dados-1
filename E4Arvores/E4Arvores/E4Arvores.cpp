/** PROGRAMA DE ESTRUTURAS DE DADOS: ARVORES **/
/** JOSE OTAVIO MIGUEL **/
/** ENGENHARIA DE COMPUTAÇÃO - UTFPR **/
/** FEITO EM MAI/17 **/
/** LINGUAGEM: C++ **/
/** IDE: MICROSOFT VISUAL STUDIO ENTERPRISE **/
/** PROFESSORA DOUTORA TANIA MEZZADRI **/
/** EXERCICIO 04 **/


#include <iostream>
#define BAR cout<<"==============================="<<endl;
#define JUMP cout << endl;

using namespace std;

//Variaveis globais
int quantos = 0; //contador da quantidade de nós

//Os nós
class Node {
public:
	int info;		//Valor do nó
	Node* pnode1;	//Nó da esquerda
	Node* pnode2;	//Nó da direita

	Node(int _info) {
		this->info = _info;
		this->pnode1 = NULL;
		this->pnode2 = NULL;
		quantos++;
		cout << quantos << endl;
	}
	~Node() {
		quantos--;
		cout << quantos << endl;
	}
};


//As árvores
class Tree {
public:

	Node* topo;

	Tree(Node* _topo) {
		this->topo = _topo;
	}
	//addNode pronta
	void addNode() {
		int valor = -1;
		cout << "Insira o valor do novo no." << endl;
		cin >> valor;
		Node *aux;
		bool inseriu = false;
		
		aux = this->topo;

		while (inseriu != true) { //enquanto não inserir o valor
			//Esquerda
			if (valor < aux->info) {
				if (aux->pnode1 == NULL) {
					aux->pnode1 = new Node(valor);
					inseriu = true;
					cout << "Inseriu na esquerda" << endl;
				}
				else {
					aux = aux->pnode1;
				}
			}
			//Direita
			else if (valor > aux->info) {
					if (aux->pnode2 == NULL) {
						aux->pnode2 = new Node(valor);
						inseriu = true;
						cout << "Inseriu na direita" << endl;
					}
					else {
						aux = aux->pnode2;
					}
			}
			//Igual
			else if (valor == aux->info) {
				cout << "Impossivel adicionar. Valor ja existente." << endl;
			}
		}


	}
	void delNode() {
		int valor;
		Node *aux0;  //Será para achar o valor a ser apagado
		Node *aux1; //Será para achar o valor nulo que recebera os galhos
		Node *aux2; //Será para direcionar o lugar onde o valor que será apagado está

		aux0 = this->topo;

		bool achou = false;
		bool existe = true;
		bool nulo = false;
		bool apagado = false;

		// Método da fusão
		cout << "Qual o valor do no a ser apagado?" << endl;
		cin >> valor;

		// Procurando pelo valor
		while (!achou && existe) {
			if (quantos != 0) {
				if (valor == aux0->info) {
					achou = true;
					cout << "Achei!" << endl;
				}
				else if (valor < aux0->info) {
					// ir para a esquerda
					if (aux0->pnode1 != NULL) {
						aux2 = aux0;
						aux0 = aux0->pnode1;
					}
					else {
						cout << "Valor nao existe" << endl;
						existe = false;
					}
				}
				else if (valor > aux0->info) {
					// ir para a direita
					if (aux0->pnode2 != NULL) {
						aux2 = aux0;
						aux0 = aux0->pnode2;
					}
					else {
						cout << "Valor nao existe" << endl;
						existe = false;
					}
				}
			}
		}
		if (achou && !apagado) {
			// Hora de deletar
			if (aux0->pnode1 != NULL && aux0->pnode2 != NULL) {
				//vai pra esquerda
				aux1 = aux0->pnode1;
				//va para a direita até achar um null
				while (!nulo) {
					if (aux1->pnode2 == NULL) {
						nulo = true;
					}
					else {
						aux1 = aux1->pnode2;
					}
				}
				//quando encontrar o null, jogue toda a arvore direita do valor a ser deletado
				//para onde está o null.
				aux1->pnode2 = aux0->pnode2;
				//coloque a arvore esquerda do valor deletado no lugar do valor e delete o valor
				if (aux0 != this->topo) { //se não for o topo
					if (valor < aux1->info) { //se for o da esquerda
						aux2->pnode1 = aux1;
						delete aux0;
						apagado = true;
					}
					else { //se for o da direita
						aux2->pnode2 = aux1;
						delete aux0;
						apagado = true;
					}
				}
				else if (aux0 == this->topo) { //se for o topo
					this->topo = aux0->pnode1;
					cout << "Topo" << endl;
					delete aux0;
					apagado = true;
				}
			}

			else if (aux0->pnode1 != NULL && aux0->pnode2 == NULL) {
				if (aux0 != this->topo) { //se não for o topo
					if (valor < aux2->info) { //se for o da esquerda
						aux2->pnode1 = aux0->pnode1;
						delete aux0;
						apagado = true;
					}
					else { //se for o da direita
						aux2->pnode2 = aux0->pnode1;
						delete aux0;
						apagado = true;
					}
				}
				else if (aux0 == this->topo) { //se for o topo
					this->topo = aux0->pnode1;
					delete aux0;
					apagado = true;
				}
			}

			else if (aux0->pnode1 == NULL && aux0->pnode2 != NULL) {
				if (aux0 != this->topo) { //se não for o topo
					if (valor < aux2->info) { //se for o da esquerda
						aux2->pnode1 = aux0->pnode2;
						delete aux0;
						apagado = true;
					}
					else { //se for o da direita
						aux2->pnode2 = aux0->pnode2;
						delete aux0;
						apagado = true;
					}
				}
				else if (aux0 == this->topo) { //se for o topo
					this->topo = aux0->pnode2;
					delete aux0;
					apagado = true;
				}
			}

			else if (aux0->pnode1 == NULL && aux0->pnode2 == NULL) {
				cout << "oi" << endl;
				if (quantos == 1) {
					delete aux0;
					apagado = true;
				}
				else if (quantos == 0) {
					cout << "Nada a apagar" << endl;
				}
				else {
					//deletar
				}
			}
		}
	}
	void showNode() {
		Node *aux = this->topo;
		bool fd = true;
		bool fe = true;
		bool filhos = true;
		//while (filhos != false) {
			if(quantos != 0)
				cout << "RAIZ: " << aux->info << " FE: ";
			if (aux->pnode1 != NULL)
				cout << aux->pnode1->info << " FD: ";
			else {
				fe = false;
				cout << "NULL" << " FD: ";
			}
			if (aux->pnode2 != NULL)
				cout << aux->pnode2->info << endl;
			else {
				fd = false;
				cout << "NULL" << endl;
			}

			if (fe == false && fd == false)
				filhos = false;
		//}
	}

};

void menu(Tree *tree) {
	float opcao = -1;
	while (1) {
		BAR
		cout << "1- Adicionar novo no." << endl;
		cout << "2- Apagar/Deletar no." << endl;
		cout << "3- Apresentar arvore." << endl;
		cout << "0- Sair da aplicacao." << endl;
		cin >> opcao;
		JUMP

			if (opcao == 0)
				break;
			else if (opcao == 1) {
				tree->addNode();
			}
			else if (opcao == 2) {
				tree->delNode();
			}
			else if (opcao == 3) {
				tree->showNode();
			}
			else
				cout << "Opcao invalida. Insira uma opcao valida." << endl;

		BAR
	}
}

int main()
{
	int valor;
	cout << "Insira o valor da raiz." << endl;
	cin >> valor;

	Node node(valor);
	Tree tree(&node);

	menu(&tree);

	return 0;
}