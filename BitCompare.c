/*
输入
NetId：网络ID号
TestConfig：要比较的对象
RefConfig：比较对象
CMask:关心的位
len：要比较对象的长度

输出
1：一样  
0：不一样
*/
uint8 CmpConfig(uint8 NetId,uint8* TestConfig,uint8* RefConfig,uint8* CMask,uint8 len)
{
    uint8 ercd = 1;
    uint8 i;
    uint8 result;

    if(NetId==0)
    {
        for(i=0;i<len;i++)
        {
            result = TestConfig[i]^RefConfig[i];
            result &= CMask[i];
            result = ~result;
            if(result != 0xFFU)
            {
                ercd = 0; /* TestConfig != RefConfig, */
                break;
            }
        }
        return ercd;
    }
    else
    {
        return 0;
    }
}
