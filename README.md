# Casa Inteligente ESP32

![Projeto Casa Inteligente](https://github.com/murilloliveiraz/CasaInteligente-IOT/blob/main/capa.png)

Este projeto utiliza o ESP32 para criar uma interface web que permite o controle de dispositivos inteligentes em uma casa, como luzes, ar-condicionado, cortinas, televisão, ventilador e cafeteira. A interface oferece botões interativos para ligar e desligar cada dispositivo e exibe o estado atual de cada um.

## 📋 Funcionalidades

- **Controle de Dispositivos**: Através de uma interface web, você pode ligar e desligar dispositivos conectados ao ESP32.
- **Interface Responsiva**: Design moderno e responsivo para acesso em diferentes dispositivos.
- **Feedback Visual**: Os botões mudam de cor conforme o estado dos dispositivos.

## 🚀 Tecnologias Utilizadas

- **ESP32**: Microcontrolador utilizado para hospedar o servidor web e controlar dispositivos.
- **HTML e CSS**: Estrutura e design da interface web.
- **JavaScript**: Envio de requisições para alternar o estado dos dispositivos e atualizar a interface.
- **C++ para Arduino**: Código fonte do ESP32.

## 📦 Como Usar

### 1. Pré-requisitos
- Placa ESP32
- Arduino IDE com suporte para ESP32 configurado
- Sensores e dispositivos conectados aos pinos de saída do ESP32

### 2. Clonar o Repositório

```bash
git clone https://github.com/murilloliveiraz/CasaInteligente-IOT.git
cd CasaInteligente-IOT
```

### 3. Configurar o Projeto

1. Abra o arquivo `.ino` na Arduino IDE.
2. Faça o upload para o ESP32.
3. Conecte-se à rede Wi-Fi exibida pelo ESP32 ou configure-o para se conectar à sua rede local.

### 4. Acessar a Interface Web

Abra um navegador e digite o IP do ESP32 (geralmente exibido no Serial Monitor da Arduino IDE) para acessar a interface de controle.

## 🛠 Próximos Passos

- **Adicionar novos dispositivos**: Ampliar o projeto para controlar mais dispositivos.
- **Monitoramento de sensores**: Incluir sensores para monitorar temperatura, umidade, etc.

## Integrantes:

- David Murillo de Oliveira Soares (RM 559078)
- Davi dos Reis Garcia (RM 556741)
- Arthur Pagani (RM 554510)
