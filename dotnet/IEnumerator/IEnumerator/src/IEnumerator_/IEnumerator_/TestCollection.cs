// ���O��Ԃ̓o�^
using System;               // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)
using System.Collections;   // �R���N�V�����N���X(System.Collections���O���)

// �e�X�g�R���N�V�����N���X
class TestCollection : IEnumerable  // TestCollection�N���X�̒�`(IEnumerable�C���^�[�t�F�C�X������.)
{

    // �����o�t�B�[���h�̒�`
    private int[] collection;   // int�^�z��collection.
    private TestEnumerator testEnumerator;  // TestEnumerator�^testEnumerator.

    // �R���X�g���N�^
    public TestCollection(int len)
    {
        
        // �z��̐���.
        collection = new int[len];  // �v�f��len��int�^�z��collection.

        // �C�i�~�����[�^�̐���.
        testEnumerator = new TestEnumerator(collection, len);   // testEnumerator�̐���.

    }

    // �C���f�N�T�̒�`
    public int this[int indexer]
    {

        // indexer�Ԗڂ�collection�v�f�ɃA�N�Z�X.
        get
        {
            return collection[indexer];
        }
        set
        {
            collection[indexer] = value;
        }

    }

    // IEnumerator��Ԃ����\�b�hGetEnumerator.
    public IEnumerator GetEnumerator()
    {

        // �Ă΂ꂽ���Ƃ��o��.
        Console.WriteLine("GetEnumerator()");   // "GetEnumerator()"�Əo��.

        // �C�i�~�����[�^�̎擾.
        return testEnumerator;  // testEnumerator��Ԃ�.

    }

}