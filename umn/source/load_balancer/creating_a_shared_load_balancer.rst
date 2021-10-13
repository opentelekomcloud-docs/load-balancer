Creating a Shared Load Balancer
===============================

Prerequisites
-------------

You have prepared everything required for creating a load balancer. For details, see `Preparations for Creating a Load Balancer <elb_ug_fz_0004.html>`__.

Load balancers receive requests from clients and route the requests to backend servers, which answer to these requests over the private network.

.. _creating-a-shared-load-balancer-1:

Creating a Shared Load Balancer
-------------------------------

#. Log in to the management console.

#. In the upper left corner of the page, click |image1| and select the desired region and project.

#. Hover on |image2| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.

#. 

   .. container::
   

      On the **Load Balancers** page, click **Create Elastic Load Balancer**. Configure the parameters based on `Table 1 <#en-us_topic_0015479967__table1312515231668>`__.

      

.. _en-us_topic_0015479967__table1312515231668:

      .. table:: **Table 1** Parameters for creating a shared load balancer

         +---------------------------------------+---------------------------------------+---------------------------------------+
         | **Parameter**                         | **Description**                       | **Example Value**                     |
         +=======================================+=======================================+=======================================+
         | Region                                | Specifies the region. Resources in    | N/A                                   |
         |                                       | different regions cannot communicate  |                                       |
         |                                       | with each other over internal         |                                       |
         |                                       | networks. For lower network latency   |                                       |
         |                                       | and faster access to resources,       |                                       |
         |                                       | select the nearest region.            |                                       |
         +---------------------------------------+---------------------------------------+---------------------------------------+
         | Network Type                          | Specifies the network type of a load  | Private network                       |
         |                                       | balancer.                             |                                       |
         |                                       |                                       |                                       |
         |                                       | -  **Public network**: The load       |                                       |
         |                                       |    balancer routes requests from the  |                                       |
         |                                       |    clients to backend servers over    |                                       |
         |                                       |    the Internet.                      |                                       |
         |                                       | -  **Private network**: The load      |                                       |
         |                                       |    balancer routes requests from the  |                                       |
         |                                       |    clients to backend servers in the  |                                       |
         |                                       |    same VPC.                          |                                       |
         +---------------------------------------+---------------------------------------+---------------------------------------+
         | VPC                                   | Specifies the VPC where the load      | N/A                                   |
         |                                       | balancer works.                       |                                       |
         |                                       |                                       |                                       |
         |                                       | Select an existing VPC or create one. |                                       |
         |                                       |                                       |                                       |
         |                                       | For more information about VPC, see   |                                       |
         |                                       | the *Virtual Private Cloud User       |                                       |
         |                                       | Guide*.                               |                                       |
         +---------------------------------------+---------------------------------------+---------------------------------------+
         | Subnet                                | Specifies the subnet that the load    | N/A                                   |
         |                                       | balancer belongs to.                  |                                       |
         +---------------------------------------+---------------------------------------+---------------------------------------+
         | Private IP Address                    | Specifies how you want the IP address | Automatically-assigned IP address     |
         |                                       | to be assigned.                       |                                       |
         |                                       |                                       |                                       |
         |                                       | -  **Automatically-assigned IP        |                                       |
         |                                       |    address**: The system              |                                       |
         |                                       |    automatically assigns an IPv4      |                                       |
         |                                       |    address to the load balancer.      |                                       |
         |                                       | -  **Manually-specified IP address**: |                                       |
         |                                       |    Manually specify an IPv4 address   |                                       |
         |                                       |    to the load balancer.              |                                       |
         +---------------------------------------+---------------------------------------+---------------------------------------+
         | EIP                                   | Specifies the public IP address that  | New EIP                               |
         |                                       | will be bound to the load balancer    |                                       |
         |                                       | for receiving and forwarding requests |                                       |
         |                                       | over the Internet.                    |                                       |
         |                                       |                                       |                                       |
         |                                       | The following options are available:  |                                       |
         |                                       |                                       |                                       |
         |                                       | -  **New EIP**: The system will       |                                       |
         |                                       |    automatically assign an EIP.       |                                       |
         |                                       | -  **Use existing**: Select an        |                                       |
         |                                       |    existing EIP.                      |                                       |
         +---------------------------------------+---------------------------------------+---------------------------------------+
         | Bandwidth                             | Specifies the bandwidth when a new    | 10 Mbit/s                             |
         |                                       | EIP is used, in the unit of Mbit/s.   |                                       |
         +---------------------------------------+---------------------------------------+---------------------------------------+
         | Name                                  | Specifies the load balancer name.     | elb-yss0                              |
         +---------------------------------------+---------------------------------------+---------------------------------------+
         | Description                           | Provides supplementary information    | N/A                                   |
         |                                       | about the load balancer.              |                                       |
         +---------------------------------------+---------------------------------------+---------------------------------------+
         | Tag                                   | Identifies load balancers so that     | -  Key: elb_key1                      |
         |                                       | they can be easily found. A tag       | -  Value: elb-01                      |
         |                                       | consists of a tag key and a tag       |                                       |
         |                                       | value. The tag key marks a tag, and   |                                       |
         |                                       | the tag value specifies specific tag  |                                       |
         |                                       | content.                              |                                       |
         |                                       |                                       |                                       |
         |                                       | For details about the naming          |                                       |
         |                                       | specifications, see `Table            |                                       |
         |                                       | 2 <#en-us_top                         |                                       |
         |                                       | ic_0015479967__table212772311610>`__. |                                       |
         +---------------------------------------+---------------------------------------+---------------------------------------+

      

.. _en-us_topic_0015479967__table212772311610:

      .. table:: **Table 2** Naming rules of load balancer tags

         +---------------------------------------+---------------------------------------+---------------------------------------+
         | **Item**                              | **Requirement**                       | **Example Value**                     |
         +=======================================+=======================================+=======================================+
         | Tag key                               | -  Cannot be left blank.              | elb_key1                              |
         |                                       | -  Must be unique for the same load   |                                       |
         |                                       |    balancer.                          |                                       |
         |                                       | -  Can contain a maximum of 36        |                                       |
         |                                       |    characters.                        |                                       |
         |                                       | -  Cannot contain asterisks (*),      |                                       |
         |                                       |    angle brackets (< and >),          |                                       |
         |                                       |    backslashes (\), equal signs (=),  |                                       |
         |                                       |    commas (,), vertical bars (|), or  |                                       |
         |                                       |    slashes (/).                       |                                       |
         |                                       | -  Can contain only the following     |                                       |
         |                                       |    character types:                   |                                       |
         |                                       |                                       |                                       |
         |                                       |    -  Uppercase letters               |                                       |
         |                                       |    -  Lowercase letters               |                                       |
         |                                       |    -  Digits                          |                                       |
         |                                       |    -  Special characters, including   |                                       |
         |                                       |       hyphens (-) and underscores (_) |                                       |
         +---------------------------------------+---------------------------------------+---------------------------------------+
         | Tag value                             | -  Can contain a maximum of 43        | elb-01                                |
         |                                       |    characters.                        |                                       |
         |                                       | -  Cannot contain asterisks (*),      |                                       |
         |                                       |    angle brackets (< and >),          |                                       |
         |                                       |    backslashes (\), equal signs (=),  |                                       |
         |                                       |    commas (,), vertical bars (|), or  |                                       |
         |                                       |    slashes (/).                       |                                       |
         |                                       | -  Can contain only the following     |                                       |
         |                                       |    character types:                   |                                       |
         |                                       |                                       |                                       |
         |                                       |    -  Uppercase letters               |                                       |
         |                                       |    -  Lowercase letters               |                                       |
         |                                       |    -  Digits                          |                                       |
         |                                       |    -  Special characters, including   |                                       |
         |                                       |       hyphens (-) and underscores (_) |                                       |
         +---------------------------------------+---------------------------------------+---------------------------------------+

#. Click **Create Now**.

#. Confirm the configuration and submit your request.

.. |image1| image:: /images/en-us_image_0241356603.png

.. |image2| image:: /images/en-us_image_0000001120894978.png

