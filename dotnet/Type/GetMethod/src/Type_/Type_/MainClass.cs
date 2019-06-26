// ���O��Ԃ̓o�^
using System;   // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)
using System.Reflection;    // ���t���N�V����(System.Reflection���O���)

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // ���\�b�h���̎擾�܂�.
        try
        {

            // "ClassLibrary.dll"�̃��[�h.
            Assembly asm = Assembly.LoadFrom("ClassLibrary.dll");   // Assembly.LoadFrom��"ClassLibrary.dll"�����[�h.
            Console.WriteLine("asm = " + asm);  // asm���o��.

            // �^(�^�C�v)�̎擾.
            Type type = asm.GetType("BGST.ClassLibraryClass");  // asm.GetType��"BGST.ClassLibraryClass"�̌^���擾��, type�Ɋi�[.
            Console.WriteLine("type = " + type);    // type���o��.

            // �C���X�^���X�̐���.
            Object obj = Activator.CreateInstance(type);    // Activator.CreateInstance��type�̃I�u�W�F�N�g�𐶐���, obj�Ɋi�[.
            Console.WriteLine("obj = " + obj);  // obj���o��.

            // ���\�b�h���̎擾.
            MethodInfo getString = type.GetMethod("GetString"); // "GetString"���\�b�h�̏���MethodInfo�^��getString�Ɋi�[.
            Console.WriteLine("getString = " + getString);  // getString���o��.

        }
        catch (Exception ex)    // ��O����
        {

            // ��O�o��
            Console.WriteLine(ex.ToString());   // ex.ToString���o��.

        }

    }

}