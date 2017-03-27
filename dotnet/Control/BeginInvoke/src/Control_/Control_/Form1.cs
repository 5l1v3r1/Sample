using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Runtime.Remoting.Messaging;    // AsyncResult�N���X(System.Runtime.Remoting.Messaging���O���)
using System.Text;
using System.Threading; // �}���`�X���b�h(System.Threading���O���)
using System.Windows.Forms;

// �f���Q�[�g�̒�`
delegate void AsyncButtonDelegate();    // �������߂�l�������֐������f���Q�[�gAsyncButtonDelegate.
delegate void RunningDelegate();        // �������߂�l�������֐������f���Q�[�gRunningDelegate.
delegate void FinishDelegate();         // �������߂�l�������֐������f���Q�[�gFinishDelegate.
delegate void StartDelegate();          // �������߂�l�������֐������f���Q�[�gStartDelegate.

namespace Control_
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        // button1���N���b�N���ꂽ��.
        private void button1_Click(object sender, EventArgs e)
        {

            // �񓯊������Ŏ��s����f���Q�[�gasyncButton�̐���.
            AsyncButtonDelegate asyncButton = new AsyncButtonDelegate(AsyncButton); // AsyncButton���Ă�AsyncButtonDelegate�I�u�W�F�N�gasyncButton�̐���.

            // �񓯊������̊�����Ɏ��s����AsyncCallback�f���Q�[�gcallback�̐���.
            AsyncCallback callback = new AsyncCallback(AsyncCallbackFunc);  // �񓯊������������AsyncCallbackFunc�����s����AsyncCallback�I�u�W�F�N�gcallback�𐶐�.

            // �񓯊������̊J�n.
            asyncButton.BeginInvoke(callback, null);    // asyncButton.BeginInvoke�Ŕ񓯊������J�n(�񓯊�����������Ɏ��s����callback��n���Ă���.)

        }

        // �񓯊������{�^�����\�b�hAsyncButton.
        public void AsyncButton()
        {

            // RunningDelegate�̐���.
            RunningDelegate running = new RunningDelegate(Running); // running�̐���.
            IAsyncResult iar1 = button1.BeginInvoke(running);   // button1.BeginInvoke��running�������\�b�h�ɈϏ�.
            button1.EndInvoke(iar1);    // button1.EndInvoke�Ŋ���.

            // 10�b�҂�.(�[���I�ȏd��������.)
            Thread.Sleep(10000);    // Thread.Sleep��10�b�x�~.

            // FinishDelegate�̐���.
            FinishDelegate finish = new FinishDelegate(Finish); // finish�̐���.
            IAsyncResult iar2 = button1.BeginInvoke(finish);    // button1.BeginInvoke��finish�������\�b�h�ɈϏ�.
            button1.EndInvoke(iar2);    // button1.EndInvoke�Ŋ���.

        }

        // �񓯊�����������̃R�[���o�b�N���\�b�hAsyncCallbackFunc.
        public void AsyncCallbackFunc(IAsyncResult ar)
        {

            // IAsyncResult�^ar��AsyncResult�ɃL���X�g.
            AsyncResult asyncRes = (AsyncResult)ar; // ar��AsyncResult�^asyncRes�ɃL���X�g.

            // �񓯊������Ŏg�����f���Q�[�g���擾.
            AsyncButtonDelegate asyncButton = (AsyncButtonDelegate)asyncRes.AsyncDelegate;   // asyncRes.AsyncDelegate���L���X�g����asyncButton���擾.

            // �񓯊������̊���.
            asyncButton.EndInvoke(ar); // asyncButton.EndInvoke�Ŋ���.

            // 3�b�҂�.(���ɖ߂�����.)
            Thread.Sleep(3000);    // Thread.Sleep��3�b�x�~.

            // StartDelegate�̐���.
            StartDelegate start = new StartDelegate(Start); // start�̐���.
            IAsyncResult iar3 = button1.BeginInvoke(start); //  button1.BeginInvoke��start�������\�b�h�ɈϏ�.
            button1.EndInvoke(iar3);    // button1.EndInvoke�Ŋ���.

        }

        // "���s��..."�ɃZ�b�g���郁�\�b�h
        public void Running()
        {

            // "�J�n"����"���s��..."��.
            button1.Text = "���s��...";    // button1.Text��"���s��..."���Z�b�g.

        }

        // "�I��"�ɃZ�b�g���郁�\�b�h
        public void Finish()
        {

            // "���s��..."����"�I��"��.
            button1.Text = "�I��";  // button1.Text��"�I��"���Z�b�g.

        }

        // "�J�n"�ɃZ�b�g���郁�\�b�h
        public void Start()
        {

            // "�I��"����"�J�n"��.
            button1.Text = "�J�n";  // button1.Text��"�J�n"���Z�b�g.

        }
    }
}