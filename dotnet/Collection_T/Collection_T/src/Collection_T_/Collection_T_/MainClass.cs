// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)
using System.Collections;   // �R���N�V�����N���X(System.Collections���O���)
using System.Collections.Generic;   // �W�F�l���b�N�R���N�V�����N���X(System.Collections.Generic���O���)
using System.Collections.ObjectModel;   // �R���N�V�����I�u�W�F�N�g���f���N���X(System.Collections.ObjectModel���O���)

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // Collection<int>�ɐ����l��ǉ�.
        Collection<int> iCol = new Collection<int>();    // new��Collection<int>�𐶐���, iCol�Ɋi�[.
        iCol.Add(1);   // 1��ǉ�.
        iCol.Add(2);   // 2��ǉ�.
        iCol.Add(3);   // 3��ǉ�.
        iCol.Add(4);   // 4��ǉ�.
        iCol.Add(5);   // 5��ǉ�.

        // foreach�Ŏ��o��.
        foreach (int i in iCol)
        {
            // �l�̎��o��.
            Console.WriteLine("i = " + i);  // i���o��.
        }

    }

}