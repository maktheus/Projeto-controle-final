def filtro_media_movel(dados, janela):
    """
    Aplica um filtro de média móvel aos dados.

    :param dados: Lista de medições de potência.
    :param janela: Número de medições a considerar para a média móvel.
    :return: Lista de valores filtrados.
    """
    filtrado = []
    soma = sum(dados[:janela])
    filtrado.append(soma / janela)  # Primeira média baseada na janela inicial

    for i in range(janela, len(dados)):
        soma += dados[i] - dados[i - janela]  # Adiciona o novo e remove o mais antigo
        filtrado.append(soma / janela)

    return filtrado

# Exemplo de uso
dados_potencia = [100, 110, 120, 130, 140, 150, 160, 170, 180, 190, 200]
janela = 3  # Define o tamanho da janela para a média móvel

potencia_media = filtro_media_movel(dados_potencia, janela)

print("Potência média filtrada:", potencia_media)
