# <p style="text-align:center"> Trabalho I | Criando um Modelador 3D

## Descrição

O objetivo deste trabalho é implementar um modelador 3D simples, utilizando OpenGL e C++. O modelador deve permitir que o usuário crie um cenário com um certo nível de detalhamento (avaliação subjetiva considerando complexidade e criatividade). O modelador deve permitir que o usuário salve e carregue o cenário em um arquivo. O modelador deve também permitir que o usuário mova a câmera pelo cenário, faça transformações, como: translação, rotação e escala.

___________________

## [`6.0 pontos`] Implementar um modelador

- [`2.5 pontos`] Implementação Orientada a Objetos (definir uma classe Object)
  - [`1.0 ponto`] Herança
    - definir um método draw (virtual) a ser implementado por classes mais específicas (herdar da classe Object), por exemplo: Tree, ...
  - [`0.5 ponto`] Transformações
    - incluir atributos relacionados a possíveis transformações: translação/rotação/escala
  - [`0.5 ponto`] Seleção
    - incluir um atributo na classe Object para dizer se o objeto está selecionado ou não se ele deve ou não ser pintado com uma cor de destaque (branco, por exemplo), use-o como um teste no método draw
  - [`0.5 ponto`] Sistema de Referência Local
    - incluir um atributo na classe Object para alternar entre desenhar ou não os eixos do sistema local do objeto. Use-o como um teste no método draw.

- [`1.5 pontos`] Manipulação do vetor de Objetos
	- [`0.5 ponto`] Permitir incluir objetos neste vetor (usando o teclado)
		- Permitir incluir objetos independentes, incluindo aqueles do mesmo tipo (mesma classe filha). Cada tipo de objeto deve estar associado a uma tecla diferente
		- Os objetos devem ser incluídos com seu centro coincidindo com a origem do sistema local; Seu sistema local deve inicialmente estar alinhado com o sistema global; Use o próprio modelador, durante sua execução, para posicionar cada objeto (selecionado) no cenário
	- [`0.5 ponto`] Permitir alternar/selecionar os objetos deste vetor (um de cada vez, seguindo a ordem do vetor)
		- Marcar o objeto selecionado (pintar com uma cor de destaque, todo o objeto com a mesma cor)
		- Definir teclas para avançar e retornar no vetor. Permitir avanço e retorno cíclicos (indo do último para o primeiro e vice-versa)
	- [`0.5 ponto`] Permitir excluir objetos deste vetor (usando o teclado)
		- Permitir excluir o objeto selecionado
		- Permitir excluir o último objeto do vetor.

- [`1.5 pontos`] Permitir modificar os atributos do objeto selecionado
	- [`1.2 pontos`] Translação/Rotação/Escala (usando o mouse)
		- Forçar o usuário a modelar o cenário a partir da execução do modelador (programa), e não diretamente no código
	- [`0.3 pontos`] Desenhar ou não os eixos do sistema local (usando alguma tecla)

- [`0.5 ponto`] Permitir salvar e carregar todos os objetos (todos os seus atributos) deste vetor para/desde um arquivo

## [`1.0 ponto`] Câmeras
- [`0.2 ponto`] Incluir implementação pronta já disponível nos exemplos (classe Camera [CameraDistante e/ou CameraJogo])
	- Que permita mover a câmera pelo cenário
- [`0.8 ponto`] Pré-estabelecer posições/orientações (pelo menos 6) de câmeras específicas, interessantes, de acordo com o cenário modelado

## [`3.0 pontos`] Modelar, salvar e carregar um cenário com um certo nível de detalhe (avaliação subjetiva considerando complexidade e criatividade)
- Baseado nos exercícios (no dropbox) ou sugestões dadas (não modelar laboratório, nem sala de aula)
	- Pelo menos 5 tipos diferentes de objetos (alguns deles podem usar 3ds)
- Pelo menos 2 objetos devem ser modelados usando glBegin(...); ... glEnd();
	- Definir o glNormal3f(...); das faces (compostas pelos vértices) corretamente
	- Pelo menos 2 faces inclinadas (ou seja, não alinhadas com os eixos do sistema local de coordenadas do objeto)(Usar transformações locais fixas pode facilitar)

***Sugestões:*** Use C++, QtCreator, OpenGL, GLUT/Qt [mais fácil usando a camada gráfica GUI]
___________________

***<p style='color:red;'>Pontuação dos itens depende da explicação feita por vídeo!<p>***