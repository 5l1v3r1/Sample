using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace ListBox_
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            // �I������Ă���A�C�e�����擾.
            MessageBox.Show((string)listBox1.SelectedItem); // listBox1.SelectedItem�őI�����ꂽ�A�C�e�����擾�ł�, �A�C�e���͕�����Ȃ̂�string�^�ɃL���X�g����MessageBox�ŕ\��.
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // listBox1�ɃA�C�e����ǉ�����.
            listBox1.Items.Add("abc");  // listBox1.Items.Add�ŕ�����"abc"��ǉ�.
            listBox1.Items.Add("def");  // listBox1.Items.Add�ŕ�����"def"��ǉ�.
            listBox1.Items.Add("ghi");  // listBox1.Items.Add�ŕ�����"ghi"��ǉ�.
        }
    }
}