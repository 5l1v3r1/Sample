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

        // List<int>�ɐ����l��ǉ�.
        List<int> iList = new List<int>();    // new��List<int>�𐶐���, iList�Ɋi�[.
        iList.Add(1);   // 1��ǉ�.
        iList.Add(2);   // 2��ǉ�.
        iList.Add(3);   // 3��ǉ�.
        iList.Add(4);   // 4��ǉ�.
        iList.Add(5);   // 5��ǉ�.

        // �Y���Ŏ��o��.
        for (int i = 0; i < iList.Count; i++)
        {
            // i�Ԗڂ��o��.
            Console.WriteLine("iList[{0}] = {1}", i, iList[i]); // iList[i]���o��.
        }

        // ��؂���̏o��.
        Console.WriteLine("-----"); // "-----"���o��.

        // foreach�Ŏ��o��.
        foreach (int i in iList)
        {
            // �l�̎��o��.
            Console.WriteLine("i = " + i);  // i���o��.
        }

        // ��؂���̏o��.
        Console.WriteLine("-----"); // "-----"���o��.

        // List<string>�ɕ������ǉ�.
        List<string> strList = new List<string>();    // new��List<string>�𐶐���, strList�Ɋi�[.
        strList.Add("A");   // "A"��ǉ�.
        strList.Add("B");   // "B"��ǉ�.
        strList.Add("C");   // "C"��ǉ�.
        strList.Add("D");   // "D"��ǉ�.
        strList.Add("E");   // "E"��ǉ�.

        // �Y���Ŏ��o��.
        for (int i = 0; i < strList.Count; i++)
        {
            // i�Ԗڂ��o��.
            Console.WriteLine("strList[{0}] = {1}", i, strList[i]); // strList[i]���o��.
        }

        // ��؂���̏o��.
        Console.WriteLine("-----"); // "-----"���o��.

        // foreach�Ŏ��o��.
        foreach (string str in strList)
        {
            // �l�̎��o��.
            Console.WriteLine("str = " + str);  // str���o��.
        }

    }

}