// Ryan Santos Martins
// Analise e Desenvolvimento de Sistemas || Turma 1 || Segundo ano
#include <iostream>
#include <string>
using namespace std;

struct Indice
{
    int codigo;
    int endereco;
};

struct Cidades
{
    int cod_cidade;
    string nome;
    string uf;
};

struct Especialidades_Medicas
{
    int cod_especialidade;
    string descricao;
};

struct Medicos
{
    int cod_medico;
    int cod_cidade;
    int cod_especialidade;
    int status;
    string nome;
    string endereco;
    string telefone;
};

struct Pacientes
{
    int cod_paciente;
    int cod_cidade;
    int status;
    string nome;
    string endereco;
};

struct CID
{
    int cod_CID;
    string descricao;
};

struct Medicamentos
{
    int cod_medicamento;
    string descricao;
    int quant_estoque;
    int estoque_min;
    int estoque_max;
    float preco_unitario;
};
struct Consultas
{
    int cod_consulta;
    int cod_paciente;
    int cod_medico;
    int cod_CID;
    int cod_medicamentos;
    int quant_medicamentos;
    string data;
    string horario;
};
void leituraIndice(struct Indice indice[], int i)
{
    cout << "\n----------Registrar indice--------------\n";
    cout << "\nCodigo digitado acima: ";
    cin >> indice[i].codigo;
    cout << "\n-------------------------------------";
    cout << "\nEndereco do codigo acima: ";
    cin >> indice[i].endereco;
}

void continuarLeitura(char &SimouNao)
{
    cout << "\nDeseja continuar?" << endl;
    cout << "-------------------------------------";
    cout << "\nS para Sim, N para Nao." << endl;
    cout << "R: ";
    cin >> SimouNao;
    cout << "-------------------------------------" << endl;
}

void menorQZero(int &codigo)
{
    while (codigo <= 0)
    {
        cout << "\nCodigo invalido!!";
        cout << "\n-------------------------------------";
        cout << "\nDigite o codigo novamente: ";
        cin >> codigo;
        cin.ignore();
    }
}
void tamanhoUf(string &uf)
{
    size_t maxLength = 2;
    while (uf.size() > maxLength)
    {
        cout << "\nNumero de caracteres invalido!";
        cout << "\n--------------------";
        cout << "\nDigite novamente: ";
        cin >> uf;
    }
}

void ordenarIndices(struct Indice indices[], int tamanho)
{
    for (int i = 0; i < tamanho - 1; i++)
    {
        for (int j = 0; j < tamanho - i - 1; j++)
        {
            if (indices[j].codigo > indices[j + 1].codigo)
            {
                Indice temp = indices[j];
                indices[j] = indices[j + 1];
                indices[j + 1] = temp;
            }
        }
    }
}

void leituraCidade(struct Cidades cid[], int &contCid, struct Indice indiceCidade[], int tamanho)
{
    cout << "\n----------Informe a Cidade--------------\n";
    int i = 0;
    char SimouNao;
    for (; i < tamanho; i++)
    {
        continuarLeitura(SimouNao);
        if (SimouNao == 'N' || SimouNao == 'n')
        {
            cout << "\nEncerrado" << endl;
            break;
        }
        cout << "\nDigite o codigo da cidade: ";
        cin >> cid[i].cod_cidade;
        cin.ignore();
        menorQZero(cid[i].cod_cidade);
        cout << "\n-------------------------------------";
        cout << "\nDigite nome da cidade: ";
        getline(cin, cid[i].nome);
        cout << "\n-------------------------------------";
        cout << "\nDigite sua UF: ";
        cin >> cid[i].uf;
        tamanhoUf(cid[i].uf);
        cout << "\n-------------------------------------";
        leituraIndice(indiceCidade, i);
    }
    contCid = i;
    ordenarIndices(indiceCidade, contCid);
}

void exibirCidadeDisponivel(struct Cidades cidade[], int contCidade)
{
    cout << "\n----------Cidades disponiveis--------------\n";
    for (int i = 0; i < contCidade; i++)
    {
        cout << "\nCodigo: " << cidade[i].cod_cidade;
        cout << "\tNome: " << cidade[i].nome;
        cout << "\n-------------------------------------";
    }
}

void exibirCidadeEscolhida(struct Cidades cidade[], int posiCidade)
{
    if (posiCidade != -1)
    {
        cout << "\n----------Cidade escolhida--------------\n";
        cout << "\nNome: " << cidade[posiCidade].nome;
        cout << "\tUF: " << cidade[posiCidade].uf;
        cout << "\n-------------------------------------";
    }
    else
    {
        cout << "\nCidade nao encontrada";
    }
}

void leituraEspecialidade(struct Especialidades_Medicas especialidade[], int &contEspecialidade, struct Indice indiceEspecialidade[], int tamanho)
{
    cout << "\n----------Informe a Especialidade--------------\n";
    int i = 0;
    char SimouNao;
    for (; i < tamanho; i++)
    {
        continuarLeitura(SimouNao);
        if (SimouNao == 'N' || SimouNao == 'n')
        {
            cout << "\nEncerrado" << endl;
            break;
        }
        cout << "\nCodigo: ";
        cin >> especialidade[i].cod_especialidade;
        cin.ignore();
        cout << "\n-------------------------------------";
        menorQZero(especialidade[i].cod_especialidade);
        cout << "\nDescricao: ";
        getline(cin, especialidade[i].descricao);
        cout << "\n-------------------------------------";
        leituraIndice(indiceEspecialidade, i);
    }
    contEspecialidade = i;
    ordenarIndices(indiceEspecialidade, contEspecialidade);
}

void exibirEspecialidadeDisponivel(struct Especialidades_Medicas especialidade[], int contEspecialidade)
{
    cout << "\n----------Especialidades disponiveis--------------\n";
    for (int i = 0; i < contEspecialidade; i++)
    {
        cout << "\nCodigo: " << especialidade[i].cod_especialidade;
        cout << "\tDescricao: " << especialidade[i].descricao;
        cout << "\n-------------------------------------";
    }
}

void exibirEspecialidadeEscolhida(struct Especialidades_Medicas especialidade[], int posiEspecialidade)
{
    if (posiEspecialidade != -1)
    {
        cout << "\n----------Especialidade escolhida--------------\n";
        cout << "\nDescricao: " << especialidade[posiEspecialidade].descricao;
    }
    else
    {
        cout << "\nEspecialidade nao encontrada";
    }
}

void leituraCID(struct CID cid[], int &contCID, struct Indice indiceCID[], int tamanho)
{
    cout << "\n----------Informe a CID--------------\n";
    int i = 0;
    char SimouNao;
    for (; i < tamanho; i++)
    {
        continuarLeitura(SimouNao);
        if (SimouNao == 'N' || SimouNao == 'n')
        {
            cout << "\nEncerrado" << endl;
            break;
        }
        cout << "\nCodigo: ";
        cin >> cid[i].cod_CID;
        cin.ignore();
        cout << "\n-------------------------------------";
        menorQZero(cid[i].cod_CID);
        cout << "\nDescricao: ";
        getline(cin, cid[i].descricao);
        cout << "\n-------------------------------------";
        leituraIndice(indiceCID, i);
    }
    contCID = i;
    ordenarIndices(indiceCID, contCID);
}

void leituraMedicamento(struct Medicamentos medicamento[], int &contMedicamento, struct Indice indiceMedicamento[], int tamanho)
{
    cout << "\n----------Informe o Medicamento--------------\n";
    int i = 0;
    char SimouNao;
    for (; i < tamanho; i++)
    {
        continuarLeitura(SimouNao);
        if (SimouNao == 'N' || SimouNao == 'n')
        {
            cout << "\nEncerrado" << endl;
            break;
        }
        cout << "\nCodigo: ";
        cin >> medicamento[i].cod_medicamento;
        cin.ignore();
        cout << "\n-------------------------------------";
        menorQZero(medicamento[i].cod_medicamento);
        cout << "\nDescricao: ";
        getline(cin, medicamento[i].descricao);
        cout << "\n-------------------------------------";
        cout << "\nQuantidade em estoque: ";
        cin >> medicamento[i].quant_estoque;
        cout << "\n-------------------------------------";
        cout << "\nEstoque minimo: ";
        cin >> medicamento[i].estoque_min;
        cout << "\n-------------------------------------";
        cout << "\nEstoque maximo: ";
        cin >> medicamento[i].estoque_max;
        cout << "\n-------------------------------------";
        cout << "\nPreco: ";
        cin >> medicamento[i].preco_unitario;
        cout << "\n-------------------------------------";
        leituraIndice(indiceMedicamento, i);
    }
    contMedicamento = i;
    ordenarIndices(indiceMedicamento, contMedicamento);
}

int buscaAleatEspecialidade(struct Especialidades_Medicas especialidade[], struct Indice indice[], int contEspecialidade, int codInformado)
{

    int i = 0, f = contEspecialidade;
    int m = (i + f) / 2;
    for (; f >= i && codInformado != indice[m].codigo; m = (i + f) / 2)
    {
        if (codInformado > indice[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }

    if (codInformado == indice[m].codigo)
    {

        return indice[m].endereco;
    }
    else
        return -1;
}

int buscaAleatCidade(struct Cidades cidade[], struct Indice indiceCidade[], int contCidade, int codInformado)
{
    int i = 0, f = contCidade;
    int m = (i + f) / 2;
    for (; f >= i && codInformado != indiceCidade[m].codigo; m = (i + f) / 2)
    {
        if (codInformado > indiceCidade[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if (codInformado == indiceCidade[m].codigo)
    {

        return indiceCidade[m].endereco;
    }
    else
        return -1;
}

int buscaAleatCID(struct CID cid[], struct Indice indiceCID[], int contCID, int codInformado)
{
    int i = 0, f = contCID;
    int m = (i + f) / 2;
    for (; f >= i && codInformado != indiceCID[m].codigo; m = (i + f) / 2)
    {
        if (codInformado > indiceCID[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if (codInformado == indiceCID[m].codigo)
    {

        return indiceCID[m].endereco;
    }
    else
        return -1;
}

int buscaAleatPaciente(struct Pacientes paciente[], struct Indice indicePaciente[], int contPaciente, int codInformado)
{
    int i = 0, f = contPaciente;
    int m = (i + f) / 2;
    for (; f >= i && codInformado != indicePaciente[m].codigo; m = (i + f) / 2)
    {
        if (codInformado > indicePaciente[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if (codInformado == indicePaciente[m].codigo)
    {

        return indicePaciente[m].endereco;
    }
    else
        return -1;
}

int buscaAleatMedicamento(struct Medicamentos medicamento[], struct Indice indiceMedicamento[], int contMedicamento, int codInformado)
{

    int i = 0, f = contMedicamento;
    int m = (i + f) / 2;
    for (; f >= i && codInformado != indiceMedicamento[m].codigo; m = (i + f) / 2)
    {
        if (codInformado > indiceMedicamento[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }

    if (codInformado == indiceMedicamento[m].codigo)
    {

        return indiceMedicamento[m].endereco;
    }
    else
        return -1;
}

void inclusaoMedico(struct Indice indiceMedico[], struct Medicos medico[], int &contMedico, int codInclusao, struct Especialidades_Medicas especialidade[], int contEspecialidade, struct Indice indiceEspecialidade[], struct Cidades cidade[], int contCid, struct Indice indiceCidade[])
{
    medico[contMedico].cod_medico = codInclusao;
    cin.ignore();
    cout << "\nNome: ";
    getline(cin, medico[contMedico].nome);
    exibirEspecialidadeDisponivel(especialidade, contEspecialidade);
    cout << "\nEspecialidade: ";
    cin >> medico[contMedico].cod_especialidade;
    cin.ignore();
    menorQZero(medico[contMedico].cod_especialidade);
    int posiEspecialidade = buscaAleatEspecialidade(especialidade, indiceEspecialidade, contEspecialidade, medico[contMedico].cod_especialidade);
    exibirEspecialidadeEscolhida(especialidade, posiEspecialidade);
    exibirCidadeDisponivel(cidade, contCid);
    cout << "\nCidade: ";
    cin >> medico[contMedico].cod_cidade;
    cin.ignore();
    menorQZero(medico[contMedico].cod_cidade);
    int posiCidade = buscaAleatCidade(cidade, indiceCidade, contCid, medico[contMedico].cod_cidade);
    exibirCidadeEscolhida(cidade, posiCidade);
    cout << "\nEndereco: ";
    getline(cin, medico[contMedico].endereco);
    cout << "\n-------------------------------------";
    cout << "\nTelefone: ";
    getline(cin, medico[contMedico].telefone);
    cout << "\n-------------------------------------";
    medico[contMedico].status = 0;
    int i = 0;
    for (i = contMedico - 1; indiceMedico[i].codigo > codInclusao && i >= 0; i--)
    {

        indiceMedico[i + 1].codigo = indiceMedico[i].codigo;
        indiceMedico[i + 1].endereco = indiceMedico[i].endereco;
    }
    indiceMedico[i + 1].codigo = codInclusao;
    indiceMedico[i + 1].endereco = contMedico;
    contMedico++;
    cout << "\nInclusao realizada com Sucesso";
    cout << "\n-------------------------------------";
}

void inclusaoPaciente(struct Indice indicePaciente[], struct Pacientes paciente[], int &contPaciente, int codInclusao, struct Cidades cidade[], int contCid, struct Indice indiceCidade[])
{

    paciente[contPaciente].cod_paciente = codInclusao;
    cin.ignore();
    cout << "\nNome: ";
    getline(cin, paciente[contPaciente].nome);
    exibirCidadeDisponivel(cidade, contCid);
    cout << "\nCidade: ";
    cin >> paciente[contPaciente].cod_cidade;
    cin.ignore();
    menorQZero(paciente[contPaciente].cod_cidade);
    int posiCidade = buscaAleatCidade(cidade, indiceCidade, contCid, paciente[contPaciente].cod_cidade);
    exibirCidadeEscolhida(cidade, posiCidade);
    cout << "\nEndereco: ";
    getline(cin, paciente[contPaciente].endereco);
    cout << "\n-------------------------------------";
    paciente[contPaciente].status = 0;
    int i = 0;
    for (i = contPaciente - 1; indicePaciente[i].codigo > codInclusao && i >= 0; i--)
    {

        indicePaciente[i + 1].codigo = indicePaciente[i].codigo;
        indicePaciente[i + 1].endereco = indicePaciente[i].endereco;
    }
    indicePaciente[i + 1].codigo = codInclusao;
    indicePaciente[i + 1].endereco = contPaciente;
    contPaciente++;
    cout << "\nInclusao realizada com Sucesso";
    cout << "\n-------------------------------------";
}

int buscaAleatMedico(struct Medicos medico[], struct Indice indice[], int contMedico, int codInformado)
{
    int i = 0, f = contMedico;
    int m = (i + f) / 2;
    for (; f >= i && codInformado != indice[m].codigo; m = (i + f) / 2)
    {
        if (codInformado > indice[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if (codInformado == indice[m].codigo)
    {

        return indice[m].endereco;
    }
    else
        return -1;
}

int buscaAleatConsulta(struct Consultas consulta[], struct Indice indiceConsulta[], int contConsulta, int codInformado)
{
    int i = 0, f = contConsulta;
    int m = (i + f) / 2;
    for (; f >= i && codInformado != indiceConsulta[m].codigo; m = (i + f) / 2)
    {
        if (codInformado > indiceConsulta[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if (codInformado == indiceConsulta[m].codigo)
    {

        return indiceConsulta[m].endereco;
    }
    else
        return -1;
}

void buscaParaIncluirMedico(struct Medicos medico[], struct Indice indiceMedico[], int &contMedico, int codInclusao, struct Especialidades_Medicas especialidade[], int contEspecialidade, struct Indice indiceEspecialidade[], struct Cidades cidade[], int contCid, struct Indice indiceCidade[])
{
    int i = 0, f = contMedico;
    int m = (i + f) / 2;
    for (; f >= i && codInclusao != indiceMedico[m].codigo; m = (i + f) / 2)
    {
        if (codInclusao > indiceMedico[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if (codInclusao == indiceMedico[m].codigo)
    {
        cout << "\nMedico ja Cadastrado";
        cout << "\n-------------------------------------";
        i = indiceMedico[m].endereco;
        cout << "\nCodigo do Medico: " << medico[i].cod_medico;
        cout << "\tNome: " << medico[i].nome;
        cout << "\n-------------------------------------";
    }
    else
        inclusaoMedico(indiceMedico, medico, contMedico, codInclusao, especialidade, contEspecialidade, indiceEspecialidade, cidade, contCid, indiceCidade);
}

void buscaParaIncluirPaciente(struct Pacientes paciente[], struct Indice indicePaciente[], int &contPaciente, int codInclusao, struct Cidades cidade[], int contCid, struct Indice indiceCidade[])
{
    int i = 0, f = contPaciente;
    int m = (i + f) / 2;
    for (; f >= i && codInclusao != indicePaciente[m].codigo; m = (i + f) / 2)
    {
        if (codInclusao > indicePaciente[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if (codInclusao == indicePaciente[m].codigo)
    {
        cout << "\nPaciente ja Cadastrado";
        cout << "\n-------------------------------------";
        i = indicePaciente[m].endereco;
        cout << "\nCodigo do Paciente: " << paciente[i].cod_paciente;
        cout << "\tNome: " << paciente[i].nome;
        cout << "\n-------------------------------------";
    }
    else
        inclusaoPaciente(indicePaciente, paciente, contPaciente, codInclusao, cidade, contCid, indiceCidade);
}

void medicoRepetido(int &codMedico, struct Indice indiceMedico[], int tamanho)
{
    for (int j = 0; j < tamanho; j++)
    {
        while (indiceMedico[j].codigo == codMedico)
        {

            cout << "\nCodigo ja inserido!!";
            cout << "\n-------------------------------------";
            cout << "\nDigite novamente: ";
            cin >> codMedico;
            cin.ignore();
        }
    }
}

void pacienteRepetido(int &codPaciente, struct Indice indicePaciente[], int tamanho)
{
    for (int j = 0; j < tamanho; j++)
    {
        while (indicePaciente[j].codigo == codPaciente)
        {

            cout << "\nCodigo ja inserido!!";
            cout << "\n-------------------------------------";
            cout << "\nDigite novamente: ";
            cin >> codPaciente;
            cin.ignore();
        }
    }
}

void leituraMedico(struct Medicos medico[], int &contMedico, struct Especialidades_Medicas especialidade[], int contEspecialidade, struct Indice indiceEspecialidade[], struct Cidades cidade[], int contCidade, struct Indice indiceCidade[], struct Indice indiceMedico[], int tamanho)
{
    cout << "\n----------Informe o Medico--------------\n";
    int i = 0;
    char SimouNao;
    for (; i < tamanho; i++)
    {
        continuarLeitura(SimouNao);
        if (SimouNao == 'N' || SimouNao == 'n')
        {
            cout << "\nEncerrado" << endl;
            break;
        }
        cout << "\nCodigo: ";
        cin >> medico[i].cod_medico;
        cin.ignore();
        menorQZero(medico[i].cod_medico);
        medicoRepetido(medico[i].cod_medico, indiceMedico, tamanho);
        cout << "\n-------------------------------------";
        cout << "\nNome: ";
        getline(cin, medico[i].nome);
        exibirEspecialidadeDisponivel(especialidade, contEspecialidade);
        cout << "\nEspecialidade: ";
        cin >> medico[i].cod_especialidade;
        cin.ignore();
        menorQZero(medico[i].cod_especialidade);
        int posiEspecialidade = buscaAleatEspecialidade(especialidade, indiceEspecialidade, contEspecialidade, medico[i].cod_especialidade);
        exibirEspecialidadeEscolhida(especialidade, posiEspecialidade);
        exibirCidadeDisponivel(cidade, contCidade);
        cout << "\nCidade: ";
        cin >> medico[i].cod_cidade;
        cin.ignore();
        menorQZero(medico[i].cod_cidade);
        int posiCidade = buscaAleatCidade(cidade, indiceCidade, contCidade, medico[i].cod_cidade);
        exibirCidadeEscolhida(cidade, posiCidade);
        cout << "\nEndereco: ";
        getline(cin, medico[i].endereco);
        cout << "\n-------------------------------------";
        cout << "\nTelefone: ";
        getline(cin, medico[i].telefone);
        cout << "\n-------------------------------------";
        medico[i].status = 0;
        leituraIndice(indiceMedico, i);
    }

    contMedico = i;
    ordenarIndices(indiceMedico, contMedico);
}

void adicionarMedico(struct Medicos medico[], struct Indice indiceMedico[], int &contMedico, struct Especialidades_Medicas especialidade[], int contEspecialidade, struct Indice indiceEspecialidade[], struct Cidades cidade[], int contCid, struct Indice indiceCidade[], int tamanho)
{
    cout << "\n----------Inclusao de Medicos--------------\n";
    char SimouNao;
    for (int codpesq = 9; codpesq != 0;)
    {
        if (contMedico >= tamanho)
        {
            cout << "\nLista  de medicos cheia!!";
            cout << "\n-------------------------------------";
            break;
        }
        continuarLeitura(SimouNao);
        if (SimouNao == 'N' || SimouNao == 'n')
        {
            cout << "\nEncerrado" << endl;
            break;
        }
        cout << "\nInforme o Codigo do Medico a ser Incluido: ";
        cin >> codpesq;
        menorQZero(codpesq);
        cout << "\n-------------------------------------";
        if (codpesq != 0)
            buscaParaIncluirMedico(medico, indiceMedico, contMedico, codpesq, especialidade, contEspecialidade, indiceEspecialidade, cidade, contCid, indiceCidade);
    }
}

void leituraPaciente(struct Pacientes paciente[], int &contPaciente, struct Cidades cidade[], int contCidade, struct Indice indiceCidade[], struct Indice indicePacientes[], int tamanho)
{
    cout << "\n----------Informe o Paciente--------------\n";
    int i = 0;
    char SimouNao;
    for (; i < tamanho; i++)
    {
        continuarLeitura(SimouNao);
        if (SimouNao == 'N' || SimouNao == 'n')
        {
            cout << "\nEncerrado" << endl;
            break;
        }
        cout << "\nCodigo: ";
        cin >> paciente[i].cod_paciente;
        cin.ignore();
        menorQZero(paciente[i].cod_paciente);
        pacienteRepetido(paciente[i].cod_paciente, indicePacientes, tamanho);
        cout << "\n-------------------------------------";
        cout << "\nNome: ";
        getline(cin, paciente[i].nome);
        exibirCidadeDisponivel(cidade, contCidade);
        cout << "\nCidade: ";
        cin >> paciente[i].cod_cidade;
        cin.ignore();
        menorQZero(paciente[i].cod_cidade);
        int posiCidade = buscaAleatCidade(cidade, indiceCidade, contCidade, paciente[i].cod_cidade);
        exibirCidadeEscolhida(cidade, posiCidade);
        cout << "\nEndereco: ";
        getline(cin, paciente[i].endereco);
        cout << "\n-------------------------------------";
        paciente[i].status = 0;
        leituraIndice(indicePacientes, i);
    }
    contPaciente = i;
    ordenarIndices(indicePacientes, contPaciente);
}

void adicionarPaciente(struct Pacientes paciente[], struct Indice indicePaciente[], int &contPaciente, struct Cidades cidade[], int contCid, struct Indice indiceCidade[], int tamanho)
{
    cout << "\n----------Inclusao de Pacientes--------------\n";
    char SimouNao;
    for (int codpesq = 9; codpesq != 0;)
    {

        if (contPaciente >= tamanho)
        {
            cout << "\nLista  de Pacientes cheia!!";
            cout << "\n-------------------------------------";
            break;
        }
        continuarLeitura(SimouNao);
        if (SimouNao == 'N' || SimouNao == 'n')
        {
            cout << "\nEncerrado" << endl;
            break;
        }
        cout << "\nInforme o Codigo do Paciente a ser Incluido: ";
        cin >> codpesq;
        menorQZero(codpesq);
        cout << "\n-------------------------------------";
        if (codpesq != 0)
            buscaParaIncluirPaciente(paciente, indicePaciente, contPaciente, codpesq, cidade, contCid, indiceCidade);
    }
}

void exibirPacienteDisponivel(struct Pacientes paciente[], int contPaciente)
{
    cout << "\n----------Pacientes disponiveis--------------\n";
    for (int i = 0; i < contPaciente; i++)
    {
        cout << "\nCodigo: " << paciente[i].cod_paciente;
        cout << "\tNome: " << paciente[i].nome;
        cout << "\n-------------------------------------";
    }
}

void exibirPacienteEscolhido(struct Pacientes paciente[], int posiPaciente, struct Cidades cidade[], int posiCidade)
{
    if (posiPaciente != -1)
    {
        cout << "\n----------Paciente escolhido--------------\n";
        cout << "\nNome: " << paciente[posiPaciente].nome;
        cout << "\tCidade: " << cidade[posiCidade].nome;
        cout << "\tUF: " << cidade[posiCidade].uf;
        cout << "\n-------------------------------------";
    }
    else
    {
        cout << "\nPaciente nao encontrado";
    }
}

void exibirMedicoDisponivel(struct Medicos medico[], int contMedico)
{
    cout << "\n----------Medicos disponiveis--------------\n";
    for (int i = 0; i < contMedico; i++)
    {
        cout << "\nCodigo: " << medico[i].cod_medico;
        cout << "\tNome: " << medico[i].nome;
        cout << "\n-------------------------------------";
    }
}

void exibirMedicoEscolhido(struct Medicos medico[], int posiMedico, struct Especialidades_Medicas especialidade[], int posiEspecialidade)
{
    if (posiMedico != -1)
    {
        cout << "\n----------Medico escolhido--------------\n";
        cout << "\nNome: " << medico[posiMedico].nome;
        cout << "\tEspecialidade: " << especialidade[posiEspecialidade].descricao;
        cout << "\n-------------------------------------";
    }
    else
    {
        cout << "\nMedico nao encontrado";
    }
}

void exibirCIDdisponivel(struct CID cid[], int contCID)
{
    cout << "\n----------CIDs disponiveis--------------\n";
    for (int i = 0; i < contCID; i++)
    {
        cout << "\nCodigo: " << cid[i].cod_CID;
        cout << "\tDescricao: " << cid[i].descricao;
        cout << "\n-------------------------------------";
    }
}

void exibirCIDescolhido(struct CID cid[], int posiCID)
{
    if (posiCID != -1)
    {
        cout << "\n----------CID escolhido--------------\n";
        cout << "\nNome: " << cid[posiCID].cod_CID;
        cout << "\tDescricao: " << cid[posiCID].descricao;
        cout << "\n-------------------------------------";
    }
    else
    {
        cout << "\nCID nao encontrada";
    }
}

void exibirMedicamentoDisponivel(struct Medicamentos medicamento[], int contMedicamento)
{
    cout << "\n----------Medicamentos disponiveis--------------\n";
    for (int i = 0; i < contMedicamento; i++)
    {
        cout << "\nCodigo: " << medicamento[i].cod_medicamento;
        cout << "\tDescricao: " << medicamento[i].descricao;
        cout << "\n-------------------------------------";
    }
}

void exibirMedicamentoEscolhido(struct Medicamentos medicamento[], int posiMedicamento)
{
    if (posiMedicamento != -1)
    {
        cout << "\n----------Medicamento escolhido--------------\n";
        cout << "\nNome: " << medicamento[posiMedicamento].cod_medicamento;
        cout << "\tDescricao: " << medicamento[posiMedicamento].descricao;
        cout << "\tQuantidade em estoque: " << medicamento[posiMedicamento].quant_estoque;
        cout << "\n-------------------------------------";
    }
    else
    {
        cout << "\nMedicamento nao encontrado";
    }
}

void verificarQuantMedicamento(struct Medicamentos medicamento[], struct Indice indiceMedicamento[], int contMedicamento, int &quantNecessaria, int posiMedicamento)
{

    while (quantNecessaria > medicamento[posiMedicamento].quant_estoque)
    {
        cout << "\nQuantidade em estoque insufuiciente!!";
        cout << "\n-------------------------------------";
        cout << "\nEstoque atual do produto: " << medicamento[posiMedicamento].quant_estoque;
        cout << "\n-------------------------------------";
        cout << "\nDigite novamente: ";
        cin >> quantNecessaria;
    }
    medicamento[posiMedicamento].quant_estoque = medicamento[posiMedicamento].quant_estoque - quantNecessaria;
}

void pesquisarMedicamento(struct Medicamentos medicamento[], struct Indice indiceMedicamento[], int contMedicamento, int tamanho)
{
    cout << "\n----------Pesquisar medicamento--------------\n";
    int medicamentoPesquisado;
    char SimouNao;

    int i = 0;
    for (; i < tamanho; i++)
    {
        continuarLeitura(SimouNao);
        if (SimouNao == 'N' || SimouNao == 'n')
        {
            cout << "\nEncerrado" << endl;
            break;
        }
        exibirMedicamentoDisponivel(medicamento, contMedicamento);
        cout << "\nDigite o codigo do medicamento que deseja: ";
        cin >> medicamentoPesquisado;
        cout << "\n-------------------------------------";
        menorQZero(medicamentoPesquisado);
        int posiMedicamento = buscaAleatMedicamento(medicamento, indiceMedicamento, contMedicamento, medicamentoPesquisado);
        if (medicamentoPesquisado == medicamento[posiMedicamento].cod_medicamento)
        {
            cout << "\nNome: " << medicamento[posiMedicamento].descricao;
            cout << "\tEstoque minimo: " << medicamento[posiMedicamento].estoque_min;
            cout << "\tEstoque maximo: " << medicamento[posiMedicamento].estoque_max;
            cout << "\n-------------------------------------";
            cout << "\nEstoque atual: " << medicamento[posiMedicamento].quant_estoque;
            cout << "\tValor unitario: " << medicamento[posiMedicamento].preco_unitario << " reais";
            cout << "\tValor do estoque inteiro: " << medicamento[posiMedicamento].quant_estoque * medicamento[posiMedicamento].preco_unitario << " reais";
            cout << "\n-------------------------------------";
        }
        else
        {
            cout << "\nMedicamento nao encontrado!!";
        }
    }
}

void medicamentoNoMinimo(struct Medicamentos medicamento[], struct Indice indiceMedicamento[], int contMedicamento)
{
    cout << "\n----------Medicamentos no minimo--------------\n";
    bool existeMedicamentoMinimo = false;
    for (int i = 0; i < contMedicamento; i++)
    {
        if (medicamento[i].quant_estoque < medicamento[i].estoque_min)
        {
            cout << "\nCodigo: " << medicamento[i].cod_medicamento;
            cout << "\tNome: " << medicamento[i].descricao;
            cout << "\tEstoque atual: " << medicamento[i].quant_estoque;
            cout << "\nEstoque maximo: " << medicamento[i].estoque_max;
            cout << "\tQuantidade a ser comprada: " << medicamento[i].estoque_max - medicamento[i].quant_estoque << " unidades";
            cout << "\tValor a ser gasto: " << (medicamento[i].estoque_max - medicamento[i].quant_estoque) * medicamento[i].preco_unitario << " reais";
            cout << "\n-------------------------------------";
            existeMedicamentoMinimo = true;
        }
    }
    if (existeMedicamentoMinimo == false)
    {
        cout << "\nTodos os medicamentos estao acima do minimo!!";
    }
    cin.get();
}

void leituraConsulta(struct Consultas consulta[], struct Indice indiceConsulta[], int &contConsulta, struct Pacientes paciente[], struct Indice indicePaciente[], int contPaciente, struct Cidades cidade[], struct Indice indiceCid[], int contCidade, struct Medicos medico[], struct Indice indiceMedico[], int contMedico, struct Especialidades_Medicas especialidade[], struct Indice indiceEspecialidade[], int contEspecialidade, struct CID cid[], struct Indice indiceCID[], int contCID, struct Medicamentos medicamento[], struct Indice indiceMedicamento[], int contMedicamento, int tamanho)
{
    cout << "\n----------Informe a Consulta--------------\n";
    int i = 0;
    char SimouNao;
    for (; i < tamanho; i++)
    {
        continuarLeitura(SimouNao);
        if (SimouNao == 'N' || SimouNao == 'n')
        {
            cout << "\nEncerrado" << endl;
            break;
        }
        cout << "\nCodigo: ";
        cin >> consulta[i].cod_consulta;
        cin.ignore();
        menorQZero(consulta[i].cod_consulta);
        exibirPacienteDisponivel(paciente, contPaciente);
        cout << "\nPaciente: ";
        cin >> consulta[i].cod_paciente;
        cin.ignore();
        menorQZero(consulta[i].cod_paciente);
        int posiPaciente = buscaAleatPaciente(paciente, indicePaciente, contPaciente, consulta[i].cod_paciente);
        int posiCidade = buscaAleatCidade(cidade, indiceCid, contCidade, paciente[posiPaciente].cod_cidade);
        exibirPacienteEscolhido(paciente, posiPaciente, cidade, posiCidade);
        exibirMedicoDisponivel(medico, contMedico);
        cout << "\nMedico: ";
        cin >> consulta[i].cod_medico;
        cin.ignore();
        menorQZero(consulta[i].cod_medico);
        int posiMedico = buscaAleatMedico(medico, indiceMedico, contMedico, consulta[i].cod_medico);
        int posiEspecialidade = buscaAleatEspecialidade(especialidade, indiceEspecialidade, contEspecialidade, medico[posiMedico].cod_especialidade);
        exibirMedicoEscolhido(medico, posiMedico, especialidade, posiEspecialidade);
        cout << "\nData: ";
        getline(cin, consulta[i].data);
        cout << "\n-------------------------------------";
        cout << "\nHorario: ";
        getline(cin, consulta[i].horario);
        cout << "\n-------------------------------------";
        exibirCIDdisponivel(cid, contCID);
        cout << "\nCID: ";
        cin >> consulta[i].cod_CID;
        cin.ignore();
        menorQZero(consulta[i].cod_CID);
        int posiCID = buscaAleatCID(cid, indiceCID, contCID, consulta[i].cod_CID);
        exibirCIDescolhido(cid, posiCID);
        exibirMedicamentoDisponivel(medicamento, contMedicamento);
        cout << "\nMedicamento: ";
        cin >> consulta[i].cod_medicamentos;
        int posiMedicamento = buscaAleatMedicamento(medicamento, indiceMedicamento, contMedicamento, consulta[i].cod_medicamentos);
        cin.ignore();
        menorQZero(consulta[i].cod_medicamentos);
        cout << "\n-------------------------------------";
        cout << "\nQuantidade de medicamentos: ";
        cin >> consulta[i].quant_medicamentos;
        verificarQuantMedicamento(medicamento, indiceMedicamento, contMedicamento, consulta[i].quant_medicamentos, posiMedicamento);
        cin.ignore();
        leituraIndice(indiceConsulta, i);
    }
    contConsulta = i;
    ordenarIndices(indiceConsulta, contConsulta);
}

void reorganizacaoPaciente(struct Indice indicePaciente[], struct Pacientes paciente[], int &contPaciente)
{
    struct Pacientes novoPaciente[contPaciente];
    int j = -1;
    for (int k = 0; k < contPaciente; k++)
    {
        int i = indicePaciente[k].endereco;
        if (paciente[i].status == 0)
        {
            j++;
            novoPaciente[j] = paciente[i];
            indicePaciente[j].codigo = novoPaciente[j].cod_paciente;
            indicePaciente[j].endereco = j;
        }
    }
    indicePaciente[j + 1].codigo = 0;
    indicePaciente[j + 1].endereco = 0;
    contPaciente = j + 1;
    for (int k = 0; k < contPaciente; k++)
    {
        int i = indicePaciente[k].endereco;
        paciente[k] = novoPaciente[i];
    }
}

void reorganizacaoMedico(struct Indice indiceMedico[], struct Medicos medico[], int &contMedico)
{
    struct Medicos novoMedico[contMedico];
    int j = -1;
    for (int k = 0; k < contMedico; k++)
    {
        int i = indiceMedico[k].endereco;
        if (medico[i].status == 0)
        {
            j++;
            novoMedico[j] = medico[i];
            indiceMedico[j].codigo = novoMedico[j].cod_medico;
            indiceMedico[j].endereco = j;
        }
    }
    indiceMedico[j + 1].codigo = 0;
    indiceMedico[j + 1].endereco = 0;
    contMedico = j + 1;
    for (int k = 0; k < contMedico; k++)
    {
        int i = indiceMedico[k].endereco;
        medico[k] = novoMedico[i];
    }
}

void buscaParaExcluirPaciente(struct Pacientes paciente[], struct Indice indicePaciente[], int &contPaciente, int codExclusao, struct Consultas consulta[], struct Indice indiceConsulta[], int contConsulta)
{
    int i = 0, f = contPaciente;
    int m = (i + f) / 2;
    for (; f >= i && codExclusao != indicePaciente[m].codigo; m = (i + f) / 2)
    {
        if (codExclusao > indicePaciente[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    for (int t = 0; t < contPaciente; t++)
    {
        if (consulta[t].cod_paciente == codExclusao)
        {
            cout << "\nPaciente com consulta agendada, impossivel deletar!!";
            return;
        }
    }
    i = indicePaciente[m].endereco;
    if ((codExclusao == indicePaciente[m].codigo) && paciente[i].status == 0)
    {
        paciente[i].status = 1;
        cout << "\nPaciente Excluido com Sucesso";
        reorganizacaoPaciente(indicePaciente, paciente, contPaciente);
    }
    else
        cout << "\nPaciente nao cadastrado";
}

void excluirPaciente(struct Pacientes paciente[], struct Indice indicePaciente[], int &contPaciente, struct Consultas consulta[], struct Indice indiceConsulta[], int contConsulta)
{
    cout << "\n----------Exclusao de Pacientes--------------\n";
    char SimouNao;

    for (int codExclusao = 9; codExclusao != 0;)
    {
        continuarLeitura(SimouNao);
        if (SimouNao == 'N' || SimouNao == 'n')
        {
            cout << "\nEncerrado" << endl;
            break;
        }
        cout << "\nInforme o Codigo do Paciente a ser Excluido: ";
        cin >> codExclusao;
        menorQZero(codExclusao);
        cout << "\n-------------------------------------";
        if (codExclusao != 0)
            buscaParaExcluirPaciente(paciente, indicePaciente, contPaciente, codExclusao, consulta, indiceConsulta, contConsulta);
    }
}

void buscaParaExcluirMedico(struct Medicos medico[], struct Indice indiceMedico[], int &contMedico, int codExclusao, struct Consultas consulta[], struct Indice indiceConsulta[], int contConsulta)
{
    int i = 0, f = contMedico;
    int m = (i + f) / 2;
    for (; f >= i && codExclusao != indiceMedico[m].codigo; m = (i + f) / 2)
    {
        if (codExclusao > indiceMedico[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    for (int t = 0; t < contMedico; t++)
    {

        if (consulta[t].cod_medico == codExclusao)
        {

            cout << "\nMedico com consulta agendada, impossivel deletar!!";
            return;
        }
    }
    i = indiceMedico[m].endereco;
    if ((codExclusao == indiceMedico[m].codigo) && medico[i].status == 0)
    {
        medico[i].status = 1;
        cout << "\nMedico Excluido com Sucesso";
        reorganizacaoMedico(indiceMedico, medico, contMedico);
    }
    else
        cout << "\nMedico nao cadastrado";
}

void excluirMedico(struct Medicos medico[], struct Indice indiceMedico[], int &contMedico, struct Consultas consulta[], struct Indice indiceConsulta[], int contConsulta)
{
    cout << "\n----------Exclusao de Medicos--------------\n";
    char SimouNao;

    for (int codExclusao = 9; codExclusao != 0;)
    {
        continuarLeitura(SimouNao);
        if (SimouNao == 'N' || SimouNao == 'n')
        {
            cout << "\nEncerrado" << endl;
            break;
        }
        cout << "\nInforme o Codigo do Medico a ser Excluido: ";
        cin >> codExclusao;
        menorQZero(codExclusao);
        cout << "\n-------------------------------------";
        if (codExclusao != 0)
            buscaParaExcluirMedico(medico, indiceMedico, contMedico, codExclusao, consulta, indiceConsulta, contConsulta);
    }
}

void exibirCidades(struct Cidades cidade[], struct Indice indiceCidade[], int contCidade)
{
    cout << "\n----------Cidades Cadastradas--------------\n";
    for (int i = 0; i < contCidade; i++)
    {
        cout << "\nCodigo: " << cidade[i].cod_cidade;
        cout << "\tNome: " << cidade[i].nome;
        cout << "\tUF: " << cidade[i].uf;
        cout << "\n-------------------------------------";
    }
}

void exibirEspecialidades(struct Especialidades_Medicas especialidade[], struct Indice indiceEspecialidade[], int contEspecialidade)
{
    cout << "\n----------Especialidades Cadastradas--------------\n";
    for (int i = 0; i < contEspecialidade; i++)
    {
        cout << "\nCodigo: " << especialidade[i].cod_especialidade;
        cout << "\tNome: " << especialidade[i].descricao;
        cout << "\n-------------------------------------";
    }
}
void exibirCID(struct CID cid[], struct Indice indiceCid[], int contCid)
{
    cout << "\n----------CID Cadastradas--------------\n";
    for (int i = 0; i < contCid; i++)
    {
        cout << "\nCodigo: " << cid[i].cod_CID;
        cout << "\tNome: " << cid[i].descricao;
        cout << "\n-------------------------------------";
    }
}

void exibirMedicamentos(struct Medicamentos medicamento[], struct Indice indiceMedicamento[], int contMedicamento)
{
    cout << "\n----------Medicamentos Cadastrados--------------\n";
    for (int i = 0; i < contMedicamento; i++)
    {
        cout << "\nCodigo: " << medicamento[i].cod_medicamento;
        cout << "\tNome: " << medicamento[i].descricao;
        cout << "\tEstoque: " << medicamento[i].quant_estoque;
        cout << "\tPreco: " << medicamento[i].preco_unitario << " Reais";
        cout << "\n-------------------------------------";
    }
}

void exibirMedicos(struct Medicos medico[], struct Indice indiceMedico[], int contMedico, struct Cidades cidade[], struct Indice indiceCidade[], int contCidade, struct Especialidades_Medicas especialidade[], struct Indice indiceEspecialidade[], int contEspecialidade)
{
    cout << "\n----------Medicos Cadastrados--------------\n";
    for (int i = 0; i < contMedico; i++)
    {

        cout << "\nCodigo: " << medico[i].cod_medico;
        cout << "\tNome: " << medico[i].nome;
        cout << "\tEndereco: " << medico[i].endereco;
        int posiCidade = buscaAleatCidade(cidade, indiceCidade, contCidade, medico[i].cod_cidade);
        cout << "\nCidade: " << cidade[posiCidade].nome;
        int posiEspecialidade = buscaAleatEspecialidade(especialidade, indiceEspecialidade, contEspecialidade, medico[i].cod_especialidade);
        cout << "\tEspecialidade: " << especialidade[posiEspecialidade].descricao;
        cout << "\tTelefone: " << medico[i].telefone;
        cout << "\n-------------------------------------";
    }
}

void exibirPacientes(struct Pacientes paciente[], struct Indice indicePaciente[], int contPaciente, struct Cidades cidade[], struct Indice indiceCidade[], int contCidade)
{
    cout << "\n----------Pacientes Cadastrados--------------\n";
    for (int i = 0; i < contPaciente; i++)
    {
        cout << "\nCodigo: " << paciente[i].cod_paciente;
        cout << "\tNome: " << paciente[i].nome;
        cout << "\nEndereco: " << paciente[i].endereco;
        int posiCidade = buscaAleatCidade(cidade, indiceCidade, contCidade, paciente[i].cod_cidade);
        cout << "\tCidade: " << cidade[posiCidade].nome;
        cout << "\n-------------------------------------";
    }
}

void exibirConsultas(struct Consultas consulta[], struct Indice indiceConsulta[], int contConsulta, struct Medicos medico[], struct Indice indiceMedico[], int contMedico, struct Pacientes paciente[], struct Indice indicePaciente[], int contPaciente)
{
    cout << "\n----------Consultas Cadastradas--------------\n";
    for (int i = 0; i < contConsulta; i++)
    {
        cout << "\nCodigo: " << consulta[i].cod_consulta;
        int posiMedico = buscaAleatMedico(medico, indiceMedico, contMedico, consulta[i].cod_medico);
        cout << "\tMedico: " << medico[posiMedico].nome;
        int posiPaciente = buscaAleatPaciente(paciente, indicePaciente, contPaciente, consulta[i].cod_paciente);
        cout << "\tPaciente: " << paciente[posiPaciente].nome;
        cout << "\nData: " << consulta[i].data;
        cout << "\tHorario: " << consulta[i].horario;
        cout << "\n-------------------------------------";
    }
}

void exibirValorConsultas(struct Consultas consulta[], struct Indice indiceConsulta[], int contConsulta, struct Medicamentos medicamento[], struct Indice indiceMedicamento[], int contMedicamento, int tamanho)
{
    cout << "\n----------Valor arrecadado de Consultas--------------\n";

    int totalArrecadado = 0;
    for (int i = 0; i < contConsulta; i++)
    {

        int posiMedicamento = buscaAleatMedicamento(medicamento, indiceMedicamento, contMedicamento, consulta[i].cod_medicamentos);
        totalArrecadado = totalArrecadado + (consulta[i].quant_medicamentos * medicamento[posiMedicamento].preco_unitario) + 100;
    }

    cout << "\nTotal arrecadado: " << totalArrecadado << " reais";
    cout << "\n-------------------------------------";
}

void lerDados(struct Cidades cidade[], struct Indice indiceCidade[], int &contCid, struct Especialidades_Medicas especialidade[], struct Indice indiceEspecialidade[], int &contEspecialidade, struct CID cid[], struct Indice indiceCID[], int &contCID, struct Medicamentos medicamento[], struct Indice indiceMedicamento[], int &contMedicamento, struct Medicos medico[], struct Indice indiceMedico[], int &contMedico, struct Pacientes paciente[], struct Indice indicePaciente[], int &contPaciente, struct Consultas consulta[], struct Indice indiceConsulta[], int &contConsulta, int tamanho)
{
    int escolha;
    system("cls");
    do
    {
        cout << "\n--- Leitura de dados ---" << endl;
        cout << "1. Cidade" << endl;
        cout << "2. Especialidade" << endl;
        cout << "3. CID" << endl;
        cout << "4. Medicamento" << endl;
        cout << "5. Medico" << endl;
        cout << "6. Paciente" << endl;
        cout << "7. Consulta" << endl;
        cout << "8. Voltar" << endl;
        cout << "Escolha uma opcao: ";
        cin >> escolha;

        switch (escolha)
        {
        case 1:
            system("cls");
            leituraCidade(cidade, contCid, indiceCidade, tamanho);
            break;
        case 2:
            system("cls");
            leituraEspecialidade(especialidade, contEspecialidade, indiceEspecialidade, tamanho);
            break;
        case 3:
            system("cls");
            leituraCID(cid, contCID, indiceCID, tamanho);
            break;
        case 4:
            system("cls");
            leituraMedicamento(medicamento, contMedicamento, indiceMedicamento, tamanho);
            break;
        case 5:
            system("cls");
            leituraMedico(medico, contMedico, especialidade, contEspecialidade, indiceEspecialidade, cidade, contCid, indiceCidade, indiceMedico, tamanho);
            break;
        case 6:
            system("cls");
            leituraPaciente(paciente, contPaciente, cidade, contCid, indiceCidade, indicePaciente, tamanho);
            break;
        case 7:
            system("cls");
            leituraConsulta(consulta, indiceConsulta, contConsulta, paciente, indicePaciente, contPaciente, cidade, indiceCidade, contCid, medico, indiceMedico, contMedico, especialidade, indiceEspecialidade, contEspecialidade, cid, indiceCID, contCID, medicamento, indiceMedicamento, contMedicamento, tamanho);
            break;
        case 8:
            system("cls");
            cout << "---------------------------------" << endl;
            cout << "\nVoltando para o Menu Principal";
            break;
        default:
            cout << "Opcao invalida! Tente novamente." << endl;
        }
        cout << endl;

    } while (escolha != 8);
}

void incluirDados(struct Medicos medico[], struct Indice indiceMedico[], int &contMedico, struct Especialidades_Medicas especialidade[], int &contEspecialidade, struct Indice indiceEspecialidade[], struct Cidades cidade[], int &contCid, struct Indice indiceCidade[], struct Pacientes paciente[], struct Indice indicePaciente[], int &contPaciente, int tamanho)
{
    int escolha;
    system("cls");
    do
    {
        cout << "\n--- Inclusao de dados ---" << endl;
        cout << "1. Medico" << endl;
        cout << "2. Paciente" << endl;
        cout << "3. Voltar" << endl;
        cout << "Escolha uma opcao: ";
        cin >> escolha;

        switch (escolha)
        {
        case 1:
            system("cls");
            adicionarMedico(medico, indiceMedico, contMedico, especialidade, contEspecialidade, indiceEspecialidade, cidade, contCid, indiceCidade, tamanho);
            break;
        case 2:
            system("cls");
            adicionarPaciente(paciente, indicePaciente, contPaciente, cidade, contCid, indiceCidade, tamanho);
            break;
        case 3:
            system("cls");
            cout << "---------------------------------" << endl;
            cout << "\nVoltando para o Menu Principal";
            break;
        default:
            cout << "Opcao invalida! Tente novamente." << endl;
        }

        cout << endl;

    } while (escolha != 3);
}

void consultarDados(struct Medicamentos medicamento[], struct Indice indiceMedicamento[], int contMedicamento, struct Consultas consulta[], struct Indice indiceConsulta[], int contConsulta, int tamanho)
{
    int escolha;
    system("cls");
    do
    {
        cout << "\n--- Consulta de dados ---" << endl;
        cout << "1. Pesquisar medicamento" << endl;
        cout << "2. Medicamentos - No minimo - " << endl;
        cout << "3. Consultas - Valor arrecadado - " << endl;
        cout << "4. Voltar" << endl;
        cout << "Escolha uma opcao: ";
        cin >> escolha;

        switch (escolha)
        {
        case 1:
            system("cls");
            pesquisarMedicamento(medicamento, indiceMedicamento, contMedicamento, tamanho);
            break;
        case 2:
            system("cls");
            medicamentoNoMinimo(medicamento, indiceMedicamento, contMedicamento);
            break;
        case 3:
            system("cls");
            exibirValorConsultas(consulta, indiceConsulta, contConsulta, medicamento, indiceMedicamento, contMedicamento, tamanho);
            break;
        case 4:
            system("cls");
            cout << "---------------------------------" << endl;
            cout << "\nVoltando para o Menu Principal";
            break;
        default:
            cout << "Opcao invalida! Tente novamente." << endl;
        }
        cout << endl;

    } while (escolha != 4);
}

void excluirDados(struct Pacientes paciente[], struct Indice indicePaciente[], int &contPaciente, struct Consultas consulta[], struct Indice indiceConsulta[], int &contConsulta, struct Medicos medico[], struct Indice indiceMedico[], int &contMedico)
{
    int escolha;
    system("cls");
    do
    {
        cout << "\n--- Exclusao de dados ---" << endl;
        cout << "1. Pacientes" << endl;
        cout << "2. Medicos " << endl;
        cout << "3. Voltar " << endl;
        cout << "Escolha uma opcao: ";
        cin >> escolha;

        switch (escolha)
        {
        case 1:
            system("cls");
            excluirPaciente(paciente, indicePaciente, contPaciente, consulta, indiceConsulta, contConsulta);
            break;
        case 2:
            system("cls");
            excluirMedico(medico, indiceMedico, contMedico, consulta, indiceConsulta, contConsulta);
            break;
        case 3:
            system("cls");
            cout << "---------------------------------" << endl;
            cout << "\nVoltando para o Menu Principal";
            break;
        default:
            system("cls");
            cout << "Opcao invalida! Tente novamente." << endl;
            break;
        }
        cout << endl;

    } while (escolha != 3);
}

void exibirDados(struct Cidades cidade[], struct Indice indiceCidade[], int contCidade, struct Especialidades_Medicas especialidade[], struct Indice indiceEspecialidade[], int contEspecialidade, struct CID cid[], struct Indice indiceCid[], int contCid, struct Medicamentos medicamento[], struct Indice indiceMedicamento[], int contMedicamento, struct Medicos medico[], struct Indice indiceMedico[], int contMedico, struct Pacientes paciente[], struct Indice indicePaciente[], int contPaciente, struct Consultas consulta[], struct Indice indiceConsulta[], int contConsulta)
{
    int escolha;
    system("cls");
    do
    {
        cout << "\n--- Impressao de dados ---" << endl;
        cout << "1. Cidades" << endl;
        cout << "2. Especialidades" << endl;
        cout << "3. CID" << endl;
        cout << "4. Medicamentos" << endl;
        cout << "5. Medicos" << endl;
        cout << "6. Pacientes" << endl;
        cout << "7. Consultas" << endl;
        cout << "8. Voltar" << endl;
        cout << "Escolha uma opcao: ";
        cin >> escolha;

        switch (escolha)
        {
        case 1:
            system("cls");
            exibirCidades(cidade, indiceCidade, contCidade);
            break;
        case 2:
            system("cls");
            exibirEspecialidades(especialidade, indiceEspecialidade, contEspecialidade);
            break;
        case 3:
            system("cls");
            exibirCID(cid, indiceCid, contCid);
            break;
        case 4:
            system("cls");
            exibirMedicamentos(medicamento, indiceMedicamento, contMedicamento);
            break;
        case 5:
            system("cls");
            exibirMedicos(medico, indiceMedico, contMedico, cidade, indiceCidade, contCidade, especialidade, indiceEspecialidade, contEspecialidade);
            break;
        case 6:
            system("cls");
            exibirPacientes(paciente, indicePaciente, contPaciente, cidade, indiceCidade, contCidade);
            break;
        case 7:
            system("cls");
            exibirConsultas(consulta, indiceConsulta, contConsulta, medico, indiceMedico, contMedico, paciente, indicePaciente, contPaciente);
            break;
        case 8:
            system("cls");
            cout << "---------------------------------" << endl;
            cout << "\nVoltando para o Menu Principal";
            break;
        default:
            cout << "Opcao invalida! Tente novamente." << endl;
        }
        cout << endl;

    } while (escolha != 8);
}

void mostrarMenu()
{
    cout << "\n----- Menu -----" << endl;
    cout << "1. Leitura de dados" << endl;
    cout << "2. Inclusao de dados" << endl;
    cout << "3. Consulta de Dados" << endl;
    cout << "4. Exclusao de dados" << endl;
    cout << "5. Impressao de dados" << endl;
    cout << "6. Finalizar Programa" << endl;
    cout << "Escolha uma opcao: ";
}

int main()
{
    int const tamanho = 10;
    Cidades cidade[tamanho];
    int contCid = 0;
    Indice indiceCidade[tamanho];

    // cidade[0].cod_cidade = 1;
    // cidade[0].nome = "Taruma";
    // cidade[0].uf = "SP";

    // cidade[1].cod_cidade = 2;
    // cidade[1].nome = "Assis";
    // cidade[1].uf = "SP";
    // contCid = 2;

    // indiceCidade[0].codigo = 1;
    // indiceCidade[0].endereco = 0;
    // indiceCidade[1].codigo = 2;
    // indiceCidade[1].endereco = 1;

    Especialidades_Medicas especialidade[tamanho];
    int contEspecialidade = 0;
    Indice indiceEspecialidade[tamanho];

    // especialidade[0].cod_especialidade = 1;
    // especialidade[0].descricao = "Cardio";
    // especialidade[1].cod_especialidade = 2;
    // especialidade[1].descricao = "Oftalmo";
    // contEspecialidade = 2;

    // indiceEspecialidade[0].codigo = 1;
    // indiceEspecialidade[0].endereco = 0;
    // indiceEspecialidade[1].codigo = 2;
    // indiceEspecialidade[1].endereco = 1;

    CID cid[tamanho];
    int contCID = 0;
    Indice indiceCID[tamanho];

    // cid[0].cod_CID = 1;
    // cid[0].descricao = "seila";
    // cid[1].cod_CID = 2;
    // cid[1].descricao = "naosei";
    // contCID = 2;

    // indiceCID[0].codigo = 1;
    // indiceCID[0].endereco = 0;
    // indiceCID[1].codigo = 2;
    // indiceCID[1].endereco = 1;

    Medicamentos medicamento[tamanho];
    int contMedicamento = 0;
    Indice indiceMedicamento[tamanho];

    // medicamento[0].cod_medicamento = 1;
    // medicamento[0].descricao = "Paracetamol";
    // medicamento[0].estoque_max = 15;
    // medicamento[0].estoque_min = 5;
    // medicamento[0].preco_unitario = 1.00;
    // medicamento[0].quant_estoque = 10;
    // medicamento[1].cod_medicamento = 2;
    // medicamento[1].descricao = "Dipirona";
    // medicamento[1].estoque_max = 15;
    // medicamento[1].estoque_min = 5;
    // medicamento[1].preco_unitario = 2.00;
    // medicamento[1].quant_estoque = 10;
    // contMedicamento = 2;

    // indiceMedicamento[0].codigo = 1;
    // indiceMedicamento[0].endereco = 0;
    // indiceMedicamento[1].codigo = 2;
    // indiceMedicamento[1].endereco = 1;

    Medicos medico[tamanho];
    Indice indiceMedico[tamanho];
    indiceMedico[0].codigo = 0;
    indiceMedico[0].endereco = 0;
    int contMedico = 0;

    /*  medico[0].cod_cidade = 1;
     medico[0].cod_especialidade = 1;
     medico[0].cod_medico = 1;
     medico[0].endereco = "Av";
     medico[0].nome = "Matheus";
     medico[0].status = 0;
     medico[0].telefone = "996933533";
     medico[1].cod_cidade = 2;
     medico[1].cod_especialidade = 2;
     medico[1].cod_medico = 2;
     medico[1].endereco = "Av";
     medico[1].nome = "Ryan";
     medico[1].status = 0;
     medico[1].telefone = "997225770";
     contMedico = 2;

     indiceMedico[0].codigo = 1;
     indiceMedico[0].endereco = 0;
     indiceMedico[1].codigo = 2;
     indiceMedico[1].endereco = 1;
  */
    Pacientes paciente[tamanho];
    Indice indicePaciente[tamanho];
    indicePaciente[0].codigo = 0;
    indicePaciente[0].endereco = 0;
    int contPaciente = 0;
    /*
        paciente[0].cod_cidade = 1;
        paciente[0].cod_paciente = 1;
        paciente[0].endereco = "Av";
        paciente[0].nome = "Quiteria";
        paciente[0].status = 0;
        paciente[1].cod_cidade = 2;
        paciente[1].cod_paciente = 2;
        paciente[1].endereco = "Av";
        paciente[1].nome = "Claudemir";
        paciente[1].status = 0;
        paciente[2].cod_cidade = 2;
        paciente[2].cod_paciente = 3;
        paciente[2].endereco = "Av";
        paciente[2].nome = "Fatima";
        paciente[2].status = 0;
        paciente[3].cod_cidade = 1;
        paciente[3].cod_paciente = 4;
        paciente[3].endereco = "Av";
        paciente[3].nome = "Giovanna";
        paciente[3].status = 0;
        contPaciente = 4;

        indicePaciente[0].codigo = 1;
        indicePaciente[0].endereco = 0;
        indicePaciente[1].codigo = 2;
        indicePaciente[1].endereco = 1;
        indicePaciente[2].codigo = 3;
        indicePaciente[2].endereco = 2;
        indicePaciente[3].codigo = 4;
        indicePaciente[3].endereco = 3;
    */
    Consultas consulta[tamanho];
    consulta[0].cod_medico = 0;
    consulta[0].cod_paciente = 0;
    int contConsulta = 0;
    Indice indiceConsulta[tamanho];
    int escolha;
    do
    {
        mostrarMenu();
        cin >> escolha;

        switch (escolha)
        {
        case 1:
            lerDados(cidade, indiceCidade, contCid, especialidade, indiceEspecialidade, contEspecialidade, cid, indiceCID, contCID, medicamento, indiceMedicamento, contMedicamento, medico, indiceMedico, contMedico, paciente, indicePaciente, contPaciente, consulta, indiceConsulta, contConsulta, tamanho);
            break;
        case 2:
            incluirDados(medico, indiceMedico, contMedico, especialidade, contEspecialidade, indiceEspecialidade, cidade, contCid, indiceCidade, paciente, indicePaciente, contPaciente, tamanho);
            break;
        case 3:
            consultarDados(medicamento, indiceMedicamento, contMedicamento, consulta, indiceConsulta, contConsulta, tamanho);
            break;
        case 4:
            excluirDados(paciente, indicePaciente, contPaciente, consulta, indiceConsulta, contConsulta, medico, indiceMedico, contMedico);
            break;
        case 5:
            exibirDados(cidade, indiceCidade, contCid, especialidade, indiceEspecialidade, contEspecialidade, cid, indiceCID, contCID, medicamento, indiceMedicamento, contMedicamento, medico, indiceMedico, contMedico, paciente, indicePaciente, contPaciente, consulta, indiceConsulta, contConsulta);
            break;
        case 6:
            cout << "---------------------------------" << endl;
            cout << "\nFinalizando Programa!!";
            break;

        default:
            cout << "\n---------------------------------";
            cout << "\nOpcao invalida! Tente novamente.";
            cout << "\n---------------------------------";
        };
    } while (escolha != 6);
    return 0;
}
