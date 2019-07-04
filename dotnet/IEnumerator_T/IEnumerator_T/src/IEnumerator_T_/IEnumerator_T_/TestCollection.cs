// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)
using System.Collections;   // �R���N�V�����N���X(System.Collections���O���)
using System.Collections.Generic;   // �W�F�l���b�N�R���N�V�����N���X(System.Collections.Generic���O���)

// �e�X�g�R���N�V�����N���X
class TestCollection<T> : IEnumerable<T>  // TestCollection<T>�N���X�̒�`(IEnumerable<T>�C���^�[�t�F�C�X������.)
{

    // �����o�t�B�[���h�̒�`
    private T[] collection;   // T�^�z��collection.
    private TestEnumerator<T> testEnumerator;  // TestEnumerator<T>�^testEnumerator.

    // �R���X�g���N�^
    public TestCollection(int len)
    {

        // �z��̐���.
        collection = new T[len];  // �v�f��len��T�^�z��collection.

        // �C�i�~�����[�^�̐���.
        testEnumerator = new TestEnumerator<T>();   // testEnumerator�̐���.

    }

    // �C���f�N�T�̒�`
    public T this[int indexer]
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

    // IEnumerator<T>��Ԃ����\�b�hGetEnumerator.
    public IEnumerator<T> GetEnumerator()
    {
        // ����͎������Ȃ�.
        Console.WriteLine("IEnumerator<T> GetEnumerator()");    // �Ƃ肠����������o�͂���.
        return testEnumerator;
    }

    // ��W�F�l���b�N���錾���Ȃ��Ƃ����Ȃ�.
    IEnumerator IEnumerable.GetEnumerator()
    {
        return this.GetEnumerator();    // IEnumerator<T>���̕���Ԃ�.
    }

}