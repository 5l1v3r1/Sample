// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)
using System.Collections;   // �R���N�V�����N���X(System.Collections���O���)

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // ArrayList�ɕ������ǉ�.
        ArrayList aryList = new ArrayList();    // new��ArrayList�𐶐���, aryList�Ɋi�[.
        aryList.Add("Element1");    // "Element1"��ǉ�.
        aryList.Add("Element2");    // "Element2"��ǉ�.
        aryList.Add("Element3");    // "Element3"��ǉ�.
        aryList.Add("Element4");    // "Element4"��ǉ�.
        aryList.Add("Element5");    // "Element5"��ǉ�.
    
        // ������̎��o��.
        foreach (Object obj in aryList) // aryList����v�f�����o��.(obj�Ɋi�[.)
        {
            // aryList�̗v�f���o��.
            String s = (String)obj; // obj��String��s�ɃL���X�g.
            Console.WriteLine("s == obj == " + s);    // s���o��.
        }
    
    }

}