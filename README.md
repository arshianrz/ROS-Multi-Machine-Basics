## 1. ROS Multiple machines:

ROS Multi machine is based on TCP protocol and can establish connection between two computers.

**Step 1**:

Set first and second PC's IP addresses in same range.

As an example:

|**PC 1**|**PC 2**|  
|--- |--- |
| 192.168.YZ.NM   | 192.168.YZ.UX  |     

**Step 2**:

Remember that in ROS Multi machine,one machine will be known as host and $roscore usually runs on it.

So we should set some commands in both PC's `.bashrc` or `.zshrc` .

To get your IP you can use these commands:

```bash
$ hostname - I
```

```
$ ifconfig
```


|**PC 1 (Host)**|**PC 2**|
|---|---|
|`export ROS_IP=<IP 1>`|`export ROS_IP=<IP 2>`|
|`export ROS_HOSTNAME=<IP 1>`|`export ROS_MASTER_URI=http://<IP 1>:11311`|
||`export ROS_HOSTNAME=<IP 2>`|

*NOTE: "You should run $roscore on HOST."* 


## 2. ROS parameters & Launch file:

**Step 1 ( Parametrs )**:

In addition to the messages that we’ve studied so far, ROS provides another mechanism
called parameters to get information to nodes.

Very common method for setting parameters is to do so within a launch file.
Setting parameters
To ask roslaunch to set a parameter value, use a param element: 

```
<param name="param-name" type="variable" ,value="param-value" />
```

Then we shoud set it in our .cpp file.
```
nodehandle.param<std::string>("default_param", default_param, "default_value");
```
*NOTE: To define a private nodehandle you shoud define it like the example below:*
```
ros::NodeHandle nh("~");
```
If you want to get it:
```
ros::param::get("~private_name", param);
```
---
**Step 2 (Launch file)**:
```
<launch>
    <node pkg="package name" name="CPP File" type="package name" output = "screen">
    </node>

    <node pkg="package name" name="CPP File" type="package name" output = "screen" >
    </node>
</launch>
```
