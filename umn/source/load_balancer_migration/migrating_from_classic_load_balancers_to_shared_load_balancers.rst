Migrating from Classic Load Balancers to Shared Load Balancers
==============================================================

Scenarios
---------

Classic load balancers are no longer provided. It is recommended that you use load balancers instead because they provide comprehensive Layer 7 load balancing and better forwarding performance.

Prerequisites
-------------

You have the **Tenant Administrator** permission.

Impacts on Traffic Routing
--------------------------

Traffic routing over persistent connections will be interrupted during migration and rollback. For the impact on traffic routing over short connections, see the following table.



.. _elb-03-qy-0001__table189291540135319:

.. table:: **Table 1** Impact on traffic routing over short connections

   +-----------------------------+-----------------------------+-----------------------------+-----------------------------+
   | Scenario                    | During Migration            | Before Finishing Migration  | Rollback                    |
   +=============================+=============================+=============================+=============================+
   | Migrating a private network | Not interrupted             | On a client that is on the  | If ARP entries are not      |
   | load balancer               |                             | same subnet as the load     | refreshed, traffic from the |
   |                             |                             | balancer, run the **arping  | client is interrupted. The  |
   |                             |                             | -b** *Private IP address of | interruption duration is    |
   |                             |                             | the classic load balancer*  | the ARP aging period, which |
   |                             |                             | command to refresh ARP      | ranges from 30s to 300s,    |
   |                             |                             | entries to ensure service   | depending on parameter      |
   |                             |                             | continuity.                 | settings of the client.     |
   |                             |                             |                             |                             |
   |                             |                             | If ARP entries are not      | To refresh ARP entries and  |
   |                             |                             | refreshed, traffic from     | shorten the interruption    |
   |                             |                             | this client will be         | duration to a few seconds,  |
   |                             |                             | interrupted. The            | run the **arping -b**       |
   |                             |                             | interruption duration is    | *Private IP address of the  |
   |                             |                             | the ARP aging period, which | classic load balancer*      |
   |                             |                             | ranges from 30s to 300s,    | command on the client.      |
   |                             |                             | depending on parameter      |                             |
   |                             |                             | settings of the client.     |                             |
   |                             |                             |                             |                             |
   |                             |                             | NOTE:                       |                             |
   |                             |                             | The private IP address of   |                             |
   |                             |                             | the classic load balancer   |                             |
   |                             |                             | is bound to the shared load |                             |
   |                             |                             | balancer.                   |                             |
   +-----------------------------+-----------------------------+-----------------------------+-----------------------------+
   | Migrating a public network  | Not interrupted             | Before you click **Finish   | Before you click **Roll     |
   | load balancer with the EIP  |                             | Migration**, ensure that    | Back**, map the domain name |
   | changed                     |                             | the domain name has been    | to the EIP of the classic   |
   |                             |                             | mapped to the new EIP of    | load balancer.              |
   |                             |                             | the newly created shared    |                             |
   |                             |                             | load balancer.              | If the EIP is not           |
   |                             |                             |                             | configured, traffic is      |
   |                             |                             | If the new EIP has not been | still routed by the shared  |
   |                             |                             | configured, traffic is      | load balancer. After you    |
   |                             |                             | still routed by the classic | click **Finish Migration**, |
   |                             |                             | load balancer. After you    | traffic routing will be     |
   |                             |                             | click **Finish Migration**, | interrupted.                |
   |                             |                             | traffic routing will be     |                             |
   |                             |                             | interrupted.                |                             |
   +-----------------------------+-----------------------------+-----------------------------+-----------------------------+
   | Migrating a public network  | After the shared load       | Not interrupted             | Not interrupted             |
   | load balancer without       | balancer is created,        |                             |                             |
   | changing the EIP            | traffic will be interrupted |                             |                             |
   |                             | for about 5s, during which  |                             |                             |
   |                             | the EIP is released from    |                             |                             |
   |                             | the classic public network  |                             |                             |
   |                             | load balancer and bound to  |                             |                             |
   |                             | the shared load balancer.   |                             |                             |
   +-----------------------------+-----------------------------+-----------------------------+-----------------------------+

Migration Process
-----------------

The following are migration processes for three scenarios:

-  Migrating a private network load balancer\ **Figure 1** Migration process
   |image1|
-  Migrating a public network load balancer with the EIP changed\ **Figure 2** Migration process
   |image2|
-  Migrating a public network load balancer without changing the EIP\ **Figure 3** Migration process
   |image3|

Migrating a Classic Load Balancer
---------------------------------

#. Log in to the management console.

#. In the upper left corner of the page, click |image4| and select the desired region and project.

#. Hover on |image5| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.

#. In the classic load balancer list, locate the load balancer you want to migrate and choose **More** > **Migrate**.

#. Check whether the load balancer to be migrated is a private network load balancer.

   -  If it is a private network load balancer, go to `6 <#elb-03-qy-0001__li640652442318>`__.
   -  If it is not a private network load balancer, go to `7 <#elb-03-qy-0001__li10489153014143>`__.

#. Run command **arping -b** *Private IP address of the classic load balancer* on the client that is on the same subnet as the load balancer to update the ARP entries. Then, go to `11 <#elb-03-qy-0001__li1683144311213>`__.\ |image6|

   The private IP address of the classic load balancer is bound to the shared load balancer.

#. Determine whether you want to change the EIP.

   -  If you want to change the EIP, go to `8 <#elb-03-qy-0001__li15100834181518>`__.
   -  If you do not want to change the EIP, go to `10 <#elb-03-qy-0001__li16313204716>`__.

#. Modify the DNS configuration to map the domain name to the EIP bound to the shared load balancer.

#. Switch to the Cloud Eye console, view monitoring data of the classic load balancer and then go to `11 <#elb-03-qy-0001__li1683144311213>`__.

   If both the number of concurrent connections and the number of new connections are 0, traffic is diverted to the shared load balancer.

#. Send requests to the shared load balancer to test whether it can route requests to associated backend servers.

#. Locate the classic load balancer that has been migrated and choose **More** > **Finish Migration**.

   The classic load balancer will be automatically deleted.

#. Switch to the load balancer list and view the newly created shared load balancer.

Rolling Back to a Classic Load Balancer
---------------------------------------

If you decide to roll back, the newly created shared load balancer will be deleted, and the original classic load balancer will be restored.

#. Log in to the management console.

#. In the upper left corner of the page, click |image7| and select the desired region and project.

#. Hover on |image8| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.

#. In the classic load balancer list, locate the load balancer you want to roll back and choose **More** > **Roll Back**.

   Alternatively, select the load balancer you want to roll back and click **Roll Back** above the load balancer list.

Batch Migration or Rollback
---------------------------

#. Log in to the management console.

#. In the upper left corner of the page, click |image9| and select the desired region and project.

#. Hover on |image10| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.

#. In the classic load balancer list, select the load balancers and click **Migrate** or **Roll Back**.

#. Perform subsequent operations as needed.

   -  If you choose **Migrate**, go to `6 <#elb-03-qy-0001__li1960334510517>`__.
   -  If you choose **Roll Back**, no further operations are required.

#. Check whether the load balancers to be migrated are private network load balancers.

   -  If they are private network load balancers, go to `7 <#elb-03-qy-0001__li126031845051>`__.
   -  If they are not private network load balancers, go to `8 <#elb-03-qy-0001__li134286139103>`__.

#. After the migration, run command **arping -b** *Private IP address of each classic load balancer* on the client that is on the same subnet as the load balancer to update the ARP entries. Then, go to `12 <#elb-03-qy-0001__li16906018234>`__.\ |image11|

   The private IP address of the classic load balancer will be bound to the shared load balancer.

#. Determine whether you want to change the EIP.

   -  If you want to change the EIP, go to `9 <#elb-03-qy-0001__li2438528242>`__.
   -  If you do not want to change the EIP, go to `11 <#elb-03-qy-0001__li1243832192415>`__.

#. Modify the DNS configuration to map the domain name to the EIP bound to each shared load balancer.

#. Switch to the Cloud Eye console, view monitoring data of each classic load balancer and then go to `12 <#elb-03-qy-0001__li16906018234>`__.

   If both the number of concurrent connections and the number of new connections are 0, traffic is diverted to the shared load balancers.

#. Send requests to shared load balancers to test whether they can route requests to associated backend servers.

#. Select all classic load balancers that have been migrated and click **Finish Migration**.

   These classic load balancers will be automatically deleted.

#. Switch to the load balancer list, view the newly created shared load balancers.

Causes of Migration Failure
---------------------------

The following are possible causes why a classic load balancer cannot be migrated:

-  The quota of the shared load balancer, listener, backend server group, or certificate is insufficient.
-  The classic load balancer is not in the **Running** state.
-  The classic load balancer listener is not in the **Running** state.
-  The shared load balancer does not support the SSL protocol.

|image12|

-  During the migration, the listeners and backend servers of the classic load balancer are also migrated. Your applications and data will not be affected. To ensure successful migration, ensure that backend servers can be accessed from 100.125.0.0/16.
-  After the migration, the original classic load balancer will be deleted and cannot be restored, and its private IP address and EIP will be used by the newly created shared load balancer. If the classic load balancer does not have an EIP, you can bind one to the newly created shared load balancer.
-  During batch migration of public network load balancers, ensure that the number of EIPs and the number of load balancers are the same. After the migration, the system automatically binds one EIP to each shared load balancer in sequence.
-  Integration with the AS service becomes invalid after the migration. Configure AS if you want to scale the number of backend servers associated with each shared load balancer.
-  Access logs stored in the OBS bucket are lost because shared load balancers do not support access logging.

.. |image1| image:: /images/en-us_image_0000001115974588.png

.. |image2| image:: /images/en-us_image_0000001115981688.png

.. |image3| image:: /images/en-us_image_0000001115974770.png

.. |image4| image:: /images/en-us_image_0241356603.png

.. |image5| image:: /images/en-us_image_0000001120894978.png

.. |image6| image:: /images/note_3.0-en-us.png
.. |image7| image:: /images/en-us_image_0241356603.png

.. |image8| image:: /images/en-us_image_0000001120894978.png

.. |image9| image:: /images/en-us_image_0241356603.png

.. |image10| image:: /images/en-us_image_0000001120894978.png

.. |image11| image:: /images/note_3.0-en-us.png
.. |image12| image:: /images/note_3.0-en-us.png
