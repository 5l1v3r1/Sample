// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)
using System.IO;    // �t�@�C�����o�͂ƃf�[�^�X�g���[��(System.IO���O���)
using System.Net;   // �l�b�g���[�N�N���X(System.Net���O���)

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // �I�u�W�F�N�g�̏�����.
        WebResponse response = null;   // WebResponse�^response��null�ŏ�����.
        Stream stream = null;          // Stream�^stream��null�ŏ�����.
        StreamReader sr = null;        // StreamReader�^sr��null�ŏ�����.

        // try�u���b�N
        try
        {

            // HTTP���N�G�X�g�̍쐬.
            WebRequest request = WebRequest.Create("http://bgstation0.com");    // WebRequest.Create��URL��"http://bgstation0.com"�ƂȂ郊�N�G�X�g���쐬.
            
            // HTTP���X�|���X�̎擾.
            response = request.GetResponse();   // request.GetResponse�Ń��X�|���X�I�u�W�F�N�gresponse���擾.

            // ���X�|���X�̃X�g���[�����擾.
            stream = response.GetResponseStream();   // response.GetResponseStream�ŃX�g���[��stream���擾.

            // �ǂݍ��݃X�g���[���ɕϊ�.
            sr = new StreamReader(stream); // stream��StreamReader�ɓn����, sr���擾.

            // �X�g���[����ǂݍ���.
            string str = sr.ReadToEnd();    // sr.ReadToEnd�œǂݍ��񂾓��e��str�Ɋi�[.

            // ���X�|���X�̓��e���o��.
            Console.Write(str); // Console.Write��str�̓��e���o��.

        }
        catch (Exception ex)    // catch�u���b�N
        {

            // ��O�̏o��.
            Console.WriteLine(ex.ToString());   // Console.WriteLine��ex.ToString()�̓��e���o��.

        }
        finally // finally�u���b�N
        {

            // ���\�[�X���.
            if (sr != null) // sr��null�łȂ����.
            {
                sr.Close(); // sr.Close�ŕ���.
            }
            if (stream != null) // stream��null�łȂ����.
            {
                stream.Close(); // stream.Close�ŕ���.
            }
            if (response != null)   // response��null�łȂ����.
            {
                response.Close();   // response.Close�ŕ���.
            }

        }

    }

}