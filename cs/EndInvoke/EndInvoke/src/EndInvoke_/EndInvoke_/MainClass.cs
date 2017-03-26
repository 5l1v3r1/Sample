// ���O��Ԃ̓o�^
using System;           // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)
using System.Threading; // �}���`�X���b�h(System.Threading���O���)

// �f���Q�[�g�̒�`.
delegate int AsyncronousFuncDelegate(int a, int b, ref int refValue);   // ������int, int, ref int��, �߂�l��int�̊֐������f���Q�[�gAsyncronousFuncDelegate.

// MainClass�̒�`
class MainClass
{
    // Main���\�b�h�̒�`
    static void Main()
    {

        // �ϐ��̐錾�E������.
        int result;         // �v�Z���ʂ��i�[����int�^result.
        int refValue = 0;   // AsyncronousFunc�ɎQ�Ɠn���œn��int�^refValue��0�ŏ�����.

        // �f���Q�[�g�̐���.
        AsyncronousFuncDelegate asyncronousFunc = new AsyncronousFuncDelegate(AsyncronousFunc); // AsyncronousFunc��񓯊����s����AsyncronousFuncDelegate�I�u�W�F�N�gasyncronousFunc�𐶐�.

        // �񓯊������̎��s.
        IAsyncResult iar = asyncronousFunc.BeginInvoke(10, 20, ref refValue, null, null);    // �R���p�C���ɂ���Đ������ꂽasyncronousFunc.BeginInvoke�Ŕ񓯊����s��, �߂�l��IAsyncResult�I�u�W�F�N�g��iar�Ɋi�[.(�����Ƃ���10, 20, refValue��n��.)

        // "Calculating..."�Əo��.
        Console.WriteLine("Calculating...");    // "Calculating..."�Əo��.

        // �v�Z���ʂ̎擾.
        result = asyncronousFunc.EndInvoke(ref refValue, iar); // asyncronousFunc.EndInvoke�Ŋ����܂ő҂���, �v�Z���ʂ��擾����.(result�ɂ�refValue�ɂ��v�Z���ʂ��i�[����Ă���.)

        // �v�Z���ʂ̏o��.
        Console.WriteLine("result = " + result);        // result�̒l���o��.
        Console.WriteLine("refValue = " + refValue);    // refValue�̒l���o��.

    }

    // �񓯊������X�^�e�B�b�N���\�b�hAsyncronousFunc.
    static int AsyncronousFunc(int a, int b, ref int refValue)
    {

        // �ϐ��̐錾
        int result; // �v�Z���ʂ��ꎞ�I�Ɋi�[����int�^result.

        // �v�Z
        result = a + b; ;   // a��b�𑫂������ʂ�result�Ɋi�[.

        // 5�b�x�~.
        Thread.Sleep(5000); // Thread.Sleep��5�b�x�~.

        // refValue�Ɋi�[.
        refValue = result;  // refValue��result���i�[.

        // �߂�l��Ԃ�.
        return result;  // return��result��Ԃ�.

    }

}