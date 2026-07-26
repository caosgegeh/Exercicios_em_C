#ifndef smart_vector_h
#define smart_vector_h

typedef struct {
    double *lista;
    int quantidade;
} Vetores;

void Iniciar(Vetores *v);

void Adicionar(Vetores *v, double valor);

void Remover(Vetores *v, int indice);

void Expor_vetores(Vetores v);

void Destruir(Vetores *v);


#endif