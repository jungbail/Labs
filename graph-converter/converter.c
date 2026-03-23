#include "adj_converter.h"

AdjMatrix * convert_list_to_matrix(AdjList * list) {
    AdjMatrix * matrix = blank_matrix(list->size);
    
    // STUDENT TODO
    for(int i = 0; i < list->size; i++){ //Run once for each vertex
        edge_t * edge = list->adj_lists[i];
        while(edge != NULL){ //Follow the linked list and fill in the edges into the matrix
            matrix->data[i][edge->vertex] = edge->weight;
            edge = edge->next;
        }
    }

    return matrix;
}

AdjList * convert_matrix_to_list(AdjMatrix * matrix) {
    AdjList * list = create_graph(matrix->size);
    
    // STUDENT TODO
    for(int i = 0; i < matrix -> size; i ++ ){
        for(int j = 0; j < matrix -> size; j++){
            if (matrix -> data[i][j] != 0){
                add_edge(list,i, j, matrix -> data[i][j]);
            }
        }
    }
    
    return list;
}