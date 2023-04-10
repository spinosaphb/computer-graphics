Trabalho 1) 10.0 pontos
*pontuação dos itens depende da explicação realizada por vídeo!
Entrega e apresentação: // ()
___________________

-[6.0] Implementar um modelador
  -[2.5] implementacao orientada a objeto (definir uma classe Objeto)
    -[1.0] heranca
      -definir um método desenhar (virtual)
        -a ser implementado por classes mais específicas (herdando da classe Objeto)
          -por exemplo: Arvore, ...
    -[0.5] transformacoes
      -incluir atributos referentes às possíveis transformações
        -translação/rotação/escala
    -[0.5] selecao
      -incluir um atributo na classe Objeto para dizer se o objeto está ou não selecionado
        -se deve ou não ser pintado com uma cor de destaque (branco, por exemplo)
        -usá-lo como teste no método desenhar
    -[0.5] sist local de referencia
      -incluir um atributo na classe Objeto para alternar entre desenhar ou não os eixos do sist local do objeto
        -usá-lo como teste no método desenhar
  -[1.5] manipulacao do vetor de Objetos
    -[0.5] permitir incluir objetos nesse vetor (usando o teclado)
      -permitir incluir objetos independentes, inclusive do mesmo tipo (mesma classe filha)
        -cada tipo de objeto deve ser associado a uma tecla diferente
      -objetos devem ser incluidos com seu centro coincidindo com a origem do sist local
        -seu sist local deve estar inicialmente alinhado com o sist global
        -usar o proprio modelador implementado, durante sua execucao, para posicionar cada objeto (selecionado) no cenario
    -[0.5] permitir alternar/selecionar os objetos desse vetor (de um a um, seguindo a ordem do vetor)
      -marcar o objeto selecionado (pintar com uma cor de destaque, o objeto inteiro com a mesma cor)
      -definir teclas para avançar e para voltar no vetor
        -permitir avanco e retorno ciclico (indo do ultimo para o primeiro e vice-versa)
    -[0.5] permitir apagar objetos desse vetor (usando o teclado)
      -permitir apagar o objeto selecionado
      -permitir apagar o ultimo objeto do vetor
  -[1.5] permitir modificar os atributos do objeto selecionado
    -[1.2] translação/rotação/escala (usando o mouse)
      -forçar o usuario a modelar o cenario a partir da execucao do modelador (programa), e nao direto no codigo
    -[0.3] desenhar ou não eixos do sist local (usando alguma tecla)
  -[0.5] permitir salvar e carregar todos os objetos (todos os seus atributos) do vetor em/de um arquivo

-[1.0] Câmeras
  -[0.2] incluir implementação pronta já disponibilizada nos exemplos (class Camera [CameraDistante e/ou CameraJogo])
    -que permite movimentar a câmera pelo cenário
  -[0.8] pré-estabelecer posições/orientações (pelo menos 6) de câmera específicas interessantes, de acordo com o cenário modelado
    -permitir alternar entre essas posições/orientações pré-estabelecidas usando o teclado
    -explicar os valores usados na função gluLookAt para cada câmera

-[3.0] Modelar, salvar e carregar um cenário com um certo nível de detalhes (avaliacao subjetiva considerando complexidade e criatividade)
  -basear-se nos exercícios (no dropbox) ou sugestões dadas (não modelar laboratório, nem sala de aula)
    -pelo menos 5 tipos de objeto diferentes (alguns deles podem usar 3ds)
  -pelo menos 2 objetos devem ser modelados usando glBegin(...);...glEnd();
    -definir os glNormal3f(...); das faces (composta pelos vértices) adequadamente
    -pelo menos 2 faces inclinadas (ou seja, não alinhadas aos eixos do sist de coordenadas local do objeto)
      -usar transformacoes locais fixas pode facilitar

___________________

Sugestão: usar C++, QtCreator, OpenGL, GLUT/Qt [mais fácil usando a camada grafica GUI]
