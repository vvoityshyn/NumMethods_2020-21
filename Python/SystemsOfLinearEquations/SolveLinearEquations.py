    import numpy as np

    m_list = [[2, 1, -1, 1], [2, -1, 0, -3], [5, 1, -1, 2], [2, -1, 1, -3]]
    A = np.array(m_list)

    inv_A = np.linalg.inv(A)

    print(inv_A)

    B = np.array([1, 2, -1, 4])
    X = np.linalg.inv(A).dot(B)

    print(X)

    X2 = np.linalg.solve(A,B)

    print(X2)