// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)
using System.Collections;   // �R���N�V�����N���X(System.Collections���O���)
using System.Collections.Generic;   // �W�F�l���b�N�R���N�V�����N���X(System.Collections.Generic���O���)

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // IList<int>�ɐ����l��ǉ�.
        IList<int> iiList = new List<int>();    // new��List<int>�𐶐���, IList<int>��iiList�Ɋi�[.
        iiList.Add(1);   // 1��ǉ�.
        iiList.Add(2);   // 2��ǉ�.
        iiList.Add(3);   // 3��ǉ�.
        iiList.Add(4);   // 4��ǉ�.
        iiList.Add(5);   // 5��ǉ�.

        // foreach��iiList������o��.
        foreach (int i in iiList)
        {
            // iiList�̗v�f���o��.
            Console.WriteLine("i = " + i);  // i���o��.
        }

        // ��؂���̏o��.
        Console.WriteLine("-----"); // "-----"���o��.

        // �Y���ŃA�N�Z�X.
        for (int i = 0; i < iiList.Count; i++)
        {
            // iiList�̗v�f���o��.
            Console.WriteLine("iiList[{0}] = {1}", i, iiList[i]); // iiList[i]���o��.
        }

    }

}