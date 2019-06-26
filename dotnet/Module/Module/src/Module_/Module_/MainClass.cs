// ���O��Ԃ̓o�^
using System;   // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)
using System.Reflection;    // ���t���N�V����(System.Reflection���O���)

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // DLL�̃��[�h�ƃ��W���[���̎擾.
        try
        {

            // "ClassLibrary.dll"�̃��[�h.
            Assembly asm = Assembly.LoadFrom("ClassLibrary.dll");   // Assembly.LoadFrom��"ClassLibrary.dll"�����[�h.
            Console.WriteLine("asm = " + asm);  // asm���o��.

            // "ClassLibrary.dll"�̃��W���[�����擾.
            Module mod = asm.GetModule("ClassLibrary.dll"); // asm.GetModule��"ClassLibrary.dll"�̃��W���[��mod���擾.
            Console.WriteLine("mod = " + mod);  // mod���o��.

            // mod�̑S�v���p�e�B���o��.
            Console.WriteLine("mod.Assembly = " + mod.Assembly);    // mod.Assembly���o��.
            Console.WriteLine("mod.FullyQualifiedName = " + mod.FullyQualifiedName); // mod.FullyQualifiedName���o��.
            Console.WriteLine("mod.MDStreamVersion = " + mod.MDStreamVersion); // mod.MDStreamVersion���o��.
            Console.WriteLine("mod.MetadataToken = " + mod.MetadataToken);  // mod.MetadataToken���o��.
            Console.WriteLine("mod.ModuleHandle = " + mod.ModuleHandle);    // mod.ModuleHandle���o��.
            Console.WriteLine("mod.ModuleVersionId = " + mod.ModuleVersionId);  // mod.ModuleVersionId���o��.
            Console.WriteLine("mod.Name = " + mod.Name); // mod.Name���o��.
            Console.WriteLine("mod.ScopeName = " + mod.ScopeName);  // mod.ScopeName���o��.

        }
        catch (Exception ex)    // ��O����
        {

            // ��O�o��
            Console.WriteLine(ex.ToString());   // ex.ToString���o��.

        }

    }

}