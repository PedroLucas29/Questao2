#include <iostream>
#include <vector>
using namespace std;

struct Paciente {
    string nome;
    int prioridade;
};

void imprimirPacientes(const vector<Paciente>& pacientes) {
    for (const auto& p : pacientes) {
        cout << "Nome: " << p.nome << " | Prioridade: " << p.prioridade << endl;
    }
    cout << "------------------------" << endl;
}

// Bubble Sort 
void bubbleSort(vector<Paciente>& pacientes) {
    int n = pacientes.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            bool precisaTrocar = false;

            if (pacientes[j].prioridade > pacientes[j + 1].prioridade) {
                precisaTrocar = true;
            }
            else if (pacientes[j].prioridade == pacientes[j + 1].prioridade &&
                pacientes[j].nome > pacientes[j + 1].nome) {
                precisaTrocar = true;
            }

            if (precisaTrocar) {
                swap(pacientes[j], pacientes[j + 1]);
            }
        }
    }
}

// Selection Sort 
void selectionSort(vector<Paciente>& pacientes) {
    int n = pacientes.size();
    for (int i = 0; i < n - 1; ++i) {
        int indiceMenor = i;
        for (int j = i + 1; j < n; ++j) {
            if (pacientes[j].prioridade < pacientes[indiceMenor].prioridade ||
                (pacientes[j].prioridade == pacientes[indiceMenor].prioridade &&
                    pacientes[j].nome < pacientes[indiceMenor].nome)) {
                indiceMenor = j;
            }
        }
        swap(pacientes[i], pacientes[indiceMenor]);
    }
}

int main() {
    vector<Paciente> pacientes = {
        {"Ana", 5}, {"Pedro", 2}, {"Carla", 4}, {"Lucas", 1},
        {"Mariana", 3}, {"Fernanda", 5}, {"Rafael", 2},
        {"Beatriz", 4}, {"Guilherme", 1}, {"Sofia", 3}
    };

    // Bubble Sort
    cout << "Ordenando com Bubble Sort:\n";
    vector<Paciente> pacientesBubble = pacientes;
    bubbleSort(pacientesBubble);
    imprimirPacientes(pacientesBubble);

    // Selection Sort
    cout << "Ordenando com Selection Sort:\n";
    vector<Paciente> pacientesSelection = pacientes;
    selectionSort(pacientesSelection);
    imprimirPacientes(pacientesSelection);

    return 0;
}