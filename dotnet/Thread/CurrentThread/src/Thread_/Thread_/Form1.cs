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
delegate void RunningDelegate(int threadId);    // threadId�������̃f���Q�[�gRunningDelegate.
delegate void FinishDelegate(int threadId); // threadId�������̃f���Q�[�gFinishDelegate.
delegate void AfterDelegate();  // �������߂�l�������֐������f���Q�[�gAfterDelegate.

namespace Thread_
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            label1.Text = "UI Thread ID: " + Thread.CurrentThread.ManagedThreadId;    // label1.Text��Thread.CurrentThread.ManagedThreadId�̓��e���Z�b�g.
        }

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
            IAsyncResult iar1 = label2.BeginInvoke(running, Thread.CurrentThread.ManagedThreadId);   // label2.BeginInvoke��running�������\�b�h�ɈϏ�.
            label2.EndInvoke(iar1);    // label1.EndInvoke�Ŋ���.

            // 10�b�҂�.(�[���I�ȏd��������.)
            Thread.Sleep(10000);    // Thread.Sleep��10�b�x�~.

            // FinishDelegate�̐���.
            FinishDelegate finish = new FinishDelegate(Finish); // finish�̐���.
            IAsyncResult iar2 = label4.BeginInvoke(finish, Thread.CurrentThread.ManagedThreadId);    // label4.BeginInvoke��finish�������\�b�h�ɈϏ�.
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

            // AfterDelegate�̐���.
            AfterDelegate after = new AfterDelegate(After); // after�̐���.
            IAsyncResult iar3 = button1.BeginInvoke(after); //  button1.BeginInvoke��after�������\�b�h�ɈϏ�.
            button1.EndInvoke(iar3);    // button1.EndInvoke�Ŋ���.

        }

        // ���s���i�K�œn���ꂽ�X���b�hID�Ƃ����̃X���b�hID���Z�b�g���郁�\�b�h
        public void Running(int threadId)
        {

            // �n���ꂽthreadId��label2�ɃZ�b�g.
            label2.Text = "Running Worker Thread ID: " + threadId;  // label2.Text�Ƀ��[�J�[�X���b�hID���Z�b�g.

            // �����̃X���b�hID��label3�ɃZ�b�g.
            label3.Text = "Running UI Thread ID: " + Thread.CurrentThread.ManagedThreadId;    // label3.Text��Thread.CurrentThread.ManagedThreadId�̓��e���Z�b�g.

        }

        // �d�������I�����ɓn���ꂽ�X���b�hID�Ƃ����̃X���b�hID���Z�b�g���郁�\�b�h
        public void Finish(int threadId)
        {

            // �n���ꂽthreadId��label4�ɃZ�b�g.
            label4.Text = "Finish Worker Thread ID: " + threadId;  // label4.Text�Ƀ��[�J�[�X���b�hID���Z�b�g.

            // �����̃X���b�hID��label5�ɃZ�b�g.
            label5.Text = "Finish UI Thread ID: " + Thread.CurrentThread.ManagedThreadId;    // label5.Text��Thread.CurrentThread.ManagedThreadId�̓��e���Z�b�g.

        }

        // �񓯊�����������Ɏ��s���郁�\�b�h.
        public void After()
        {

            // ���b�Z�[�W�{�b�N�X�̕\��.
            MessageBox.Show("After");   // "After"�ƕ\��.

        }

    }
}