// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)
using System.Collections;   // �R���N�V�����N���X(System.Collections���O���)

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // IList��ArrayList�I�u�W�F�N�g�C���X�^���X�ɃA�N�Z�X.
        IList iList = new ArrayList();  // new��ArrayList�I�u�W�F�N�g�C���X�^���X�𐶐���, IList�I�u�W�F�N�g�Ɋi�[.
        iList.Add("A"); // iList.Add��"A"��ǉ�.
        iList.Add("B"); // iList.Add��"B"��ǉ�.
        iList.Add("C"); // iList.Add��"C"��ǉ�.
        iList.Add("D"); // iList.Add��"D"��ǉ�.
        iList.Add("E"); // iList.Add��"E"��ǉ�.

        // foreach��iList������o��.
        foreach (Object obj in iList)
        {
            // iList�̗v�f���o��.
            string s = (string)obj; // obj��string��s�ɃL���X�g.
            Console.WriteLine("s = " + s);  // s���o��.
        }

        // ��؂���̏o��.
        Console.WriteLine("-----"); // "-----"���o��.

        // �Y���ŃA�N�Z�X.
        for (int i = 0; i < iList.Count; i++)
        {
            // iList�̗v�f���o��.
            Console.WriteLine("iList[{0}] = {1}", i, (string)iList[i]); // iList[i]���o��.
        }

    }

}