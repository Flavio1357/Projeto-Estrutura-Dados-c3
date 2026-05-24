# 🔐 Tabela Hash em C

Implementação de uma **Tabela Hash com Encadeamento Separado** para armazenamento de usuários e validação de login.

---

## 👨‍💻 Autores

Projeto desenvolvido em grupo por:

- Davi de França Vasconcelos Nunes  
- Flavio da Silva França Filho
- Luiz Fernando de Melo  

---

## 📌 Descrição

Este projeto tem como objetivo implementar uma **Tabela Hash**, utilizando **encadeamento separado** para tratar colisões.

A tabela armazena usuários com:
- `username` (usado como chave de hash)
- `hash da senha` (usado para validação)

---

## ⚙️ Funcionalidades

- `criaHash` → Cria e inicializa a tabela hash  
- `insereHash` → Insere um novo usuário  
- `buscaHash` → Busca um usuário e valida a senha  
- `removeHash` → Remove um usuário da tabela  
- `imprimeHash` → Exibe o conteúdo da tabela  
- `liberaHash` → Libera toda a memória alocada  

---

## 💻 Como compilar

No terminal (Linux, Mac ou Windows com MinGW):

```
gcc tabelaHash.c -o programa
```

---

## ▶️ Como executar

- Linux / Mac

```
./programa
```

- Windows
```
.\programa.exe
```