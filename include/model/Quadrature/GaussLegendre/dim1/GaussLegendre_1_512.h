 /* This file is part of MODEL, the Mechanics Of Defect Evolution Library. 
 * 
 * Copyright (C) 2011 by Giacomo Po <gpo@ucla.edu>. 
 * 
 * model is distributed without any warranty under the 
 * GNU General Public License (GPL) v2 <http://www.gnu.org/licenses/>. 
 */

/*** This file is automatically generated by generateGaussLegendre.cpp ***/
#ifndef model_GAUSSLEGENDRE_1_512_H_ 
#define model_GAUSSLEGENDRE_1_512_H_ 

namespace model
{

   template<>
   struct GaussLegendre<1,512>
   {
       static Eigen::Matrix<double,2,512> abcsissasAndWeights()
       {
           Eigen::Matrix<double,512,2> aw;
           aw<<5.504507810449866e-06, 1.412631868739613e-05, 
               2.900269657790666e-05, 3.288286583112624e-05, 
               7.127681501090111e-05, 5.166595174680075e-05, 
               1.323346644794832e-04, 7.044950869391592e-05, 
               2.121751008451467e-04, 8.923090277287139e-05, 
               3.107953987010470e-04, 1.080090889875350e-04, 
               4.281919438114401e-04, 1.267832717860715e-04, 
               5.643603622758064e-04, 1.455527151258942e-04, 
               7.192955549802371e-04, 1.643167014257162e-04, 
               8.929917091938244e-04, 1.830745200178446e-04, 
               1.085442303218109e-03, 2.018254632682001e-04, 
               1.296640108574498e-03, 2.205688250904357e-04, 
               1.526577191198419e-03, 2.393039003338733e-04, 
               1.775244912212204e-03, 2.580299844982599e-04, 
               2.042633928512450e-03, 2.767463736216194e-04, 
               2.328734193267123e-03, 2.954523642016782e-04, 
               2.633534956386518e-03, 3.141472532104869e-04, 
               2.957024764972560e-03, 3.328303380788484e-04, 
               3.299191463793427e-03, 3.515009167039302e-04, 
               3.660022195757007e-03, 3.701582874735315e-04, 
               4.039503402414713e-03, 3.888017492826709e-04, 
               4.437620824476352e-03, 4.074306015653216e-04, 
               4.854359502356964e-03, 4.260441442990519e-04, 
               5.289703776741983e-03, 4.446416780530620e-04, 
               5.743637289181924e-03, 4.632225039917084e-04, 
               6.216142982708339e-03, 4.817859239113834e-04, 
               6.707203102475023e-03, 5.003312402690140e-04, 
               7.216799196430423e-03, 5.188577562039219e-04, 
               7.744912116009806e-03, 5.373647755525031e-04, 
               8.291522016857344e-03, 5.558516028951868e-04, 
               8.856608359570417e-03, 5.743175435688814e-04, 
               9.440149910471207e-03, 5.927619036945190e-04, 
               1.004212474241095e-02, 6.111839902026848e-04, 
               1.066251023558673e-02, 6.295831108675140e-04, 
               1.130128307839623e-02, 6.479585743195157e-04, 
               1.195841926831376e-02, 6.663096900770460e-04, 
               1.263389411279098e-02, 6.846357685842598e-04, 
               1.332768223018344e-02, 7.029361212198701e-04, 
               1.403975755070819e-02, 7.212100603222377e-04, 
               1.477009331742024e-02, 7.394568992354787e-04, 
               1.551866208722097e-02, 7.576759523118837e-04, 
               1.628543573188779e-02, 7.758665349547638e-04, 
               1.707038543912925e-02, 7.940279636309867e-04, 
               1.787348171367170e-02, 8.121595559095046e-04, 
               1.869469437836419e-02, 8.302606304753958e-04, 
               1.953399257531546e-02, 8.483305071601768e-04, 
               2.039134476705173e-02, 8.663685069772270e-04, 
               2.126671873769925e-02, 8.843739521219564e-04, 
               2.216008159420152e-02, 9.023461660245810e-04, 
               2.307139976754713e-02, 9.202844733636386e-04, 
               2.400063901403954e-02, 9.381882000852095e-04, 
               2.494776441657881e-02, 9.560566734390907e-04, 
               2.591274038597285e-02, 9.738892219986676e-04, 
               2.689553066227601e-02, 9.916851756944364e-04, 
               2.789609831615419e-02, 1.009443865818503e-03, 
               2.891440575026999e-02, 1.027164625070690e-03, 
               2.995041470069493e-02, 1.044846787575649e-03, 
               3.100408623834855e-02, 1.062489688909008e-03, 
               3.207538077045979e-02, 1.080092666125575e-03, 
               3.316425804205780e-02, 1.097655057767370e-03, 
               3.427067713747983e-02, 1.115176203915933e-03, 
               3.539459648191395e-02, 1.132655446193728e-03, 
               3.653597384295854e-02, 1.150092127800495e-03, 
               3.769476633220736e-02, 1.167485593537607e-03, 
               3.887093040686401e-02, 1.184835189824432e-03, 
               4.006442187137871e-02, 1.202140264734059e-03, 
               4.127519587910489e-02, 1.219400168013293e-03, 
               4.250320693398829e-02, 1.236614251102588e-03, 
               4.374840889227677e-02, 1.253781867159072e-03, 
               4.501075496425128e-02, 1.270902371099724e-03, 
               4.629019771598292e-02, 1.287975119605555e-03, 
               4.758668907112179e-02, 1.304999471146782e-03, 
               4.890018031269672e-02, 1.321974786015410e-03, 
               5.023062208495166e-02, 1.338900426349366e-03, 
               5.157796439519274e-02, 1.355775756147597e-03, 
               5.294215661567614e-02, 1.372600141304175e-03, 
               5.432314748550487e-02, 1.389372949626398e-03, 
               5.572088511255052e-02, 1.406093550862738e-03, 
               5.713531697541269e-02, 1.422761316713684e-03, 
               5.856638992538959e-02, 1.439375620871937e-03, 
               6.001405018847233e-02, 1.455935839041800e-03, 
               6.147824336736402e-02, 1.472441348953274e-03, 
               6.295891444353091e-02, 1.488891530395805e-03, 
               6.445600777926463e-02, 1.505285765237087e-03, 
               6.596946711977214e-02, 1.521623437449881e-03, 
               6.749923559529331e-02, 1.537903933127796e-03, 
               6.904525572323489e-02, 1.554126640510474e-03, 
               7.060746941033103e-02, 1.570290950018480e-03, 
               7.218581795482770e-02, 1.586396254259438e-03, 
               7.378024204868527e-02, 1.602441948064407e-03, 
               7.539068177980895e-02, 1.618427428497927e-03, 
               7.701707663430507e-02, 1.634352094885766e-03, 
               7.865936549874541e-02, 1.650215348844377e-03, 
               8.031748666246952e-02, 1.666016594300069e-03, 
               8.199137781990096e-02, 1.681755237503936e-03, 
               8.368097607289332e-02, 1.697430687052500e-03, 
               8.538621793308904e-02, 1.713042353933645e-03, 
               8.710703932430414e-02, 1.728589651520608e-03, 
               8.884337558493821e-02, 1.744071995608969e-03, 
               9.059516147040697e-02, 1.759488804433167e-03, 
               9.236233115558745e-02, 1.774839498689792e-03, 
               9.414481823729787e-02, 1.790123501563320e-03, 
               9.594255573678839e-02, 1.805340238742243e-03, 
               9.775547610225821e-02, 1.820489138437221e-03, 
               9.958351121139686e-02, 1.835569631418950e-03, 
               1.014265923739416e-01, 1.850581151022197e-03, 
               1.032846503342585e-01, 1.865523133168635e-03, 
               1.051576152739460e-01, 1.880395016405362e-03, 
               1.070454168144583e-01, 1.895196241900282e-03, 
               1.089479840197484e-01, 1.909926253486509e-03, 
               1.108652453989335e-01, 1.924584497665766e-03, 
               1.127971289089843e-01, 1.939170423644606e-03, 
               1.147435619574294e-01, 1.953683483337891e-03, 
               1.167044714050850e-01, 1.968123131401766e-03, 
               1.186797835687994e-01, 1.982488825256865e-03, 
               1.206694242242280e-01, 1.996780025093956e-03, 
               1.226733186086134e-01, 2.010996193906205e-03, 
               1.246913914236062e-01, 2.025136797508469e-03, 
               1.267235668380833e-01, 2.039201304556684e-03, 
               1.287697684910036e-01, 2.053189186555845e-03, 
               1.308299194942776e-01, 2.067099917902114e-03, 
               1.329039424356531e-01, 2.080932975883253e-03, 
               1.349917593816265e-01, 2.094687840709375e-03, 
               1.370932918803703e-01, 2.108363995528268e-03, 
               1.392084609646810e-01, 2.121960926442063e-03, 
               1.413371871549471e-01, 2.135478122533498e-03, 
               1.434793904621354e-01, 2.148915075883577e-03, 
               1.456349903907956e-01, 2.162271281582054e-03, 
               1.478039059420870e-01, 2.175546237754683e-03, 
               1.499860556168207e-01, 2.188739445582391e-03, 
               1.521813574185211e-01, 2.201850409318078e-03, 
               1.543897288565090e-01, 2.214878636306537e-03, 
               1.566110869490003e-01, 2.227823636994634e-03, 
               1.588453482262249e-01, 2.240684924962516e-03, 
               1.610924287335613e-01, 2.253462016935817e-03, 
               1.633522440346934e-01, 2.266154432801080e-03, 
               1.656247092147813e-01, 2.278761695627554e-03, 
               1.679097388836553e-01, 2.291283331685033e-03, 
               1.702072471790206e-01, 2.303718870459104e-03, 
               1.725171477696849e-01, 2.316067844675896e-03, 
               1.748393538588058e-01, 2.328329790305020e-03, 
               1.771737781871465e-01, 2.340504246594893e-03, 
               1.795203330363572e-01, 2.352590756078827e-03, 
               1.818789302322746e-01, 2.364588864589761e-03, 
               1.842494811482298e-01, 2.376498121290027e-03, 
               1.866318967083805e-01, 2.388318078678759e-03, 
               1.890260873910610e-01, 2.400048292603440e-03, 
               1.914319632321403e-01, 2.411688322295296e-03, 
               1.938494338284068e-01, 2.423237730365989e-03, 
               1.962784083409659e-01, 2.434696082834953e-03, 
               1.987187954986505e-01, 2.446062949143188e-03, 
               2.011705036014511e-01, 2.457337902168325e-03, 
               2.036334405239636e-01, 2.468520518242869e-03, 
               2.061075137188494e-01, 2.479610377170205e-03, 
               2.085926302203125e-01, 2.490607062237271e-03, 
               2.110886966475944e-01, 2.501510160231742e-03, 
               2.135956192084814e-01, 2.512319261458045e-03, 
               2.161133037028299e-01, 2.523033959755929e-03, 
               2.186416555261056e-01, 2.533653852507803e-03, 
               2.211805796729390e-01, 2.544178540661756e-03, 
               2.237299807406949e-01, 2.554607628739375e-03, 
               2.262897629330565e-01, 2.564940724859051e-03, 
               2.288598300636268e-01, 2.575177440746046e-03, 
               2.314400855595411e-01, 2.585317391744146e-03, 
               2.340304324650965e-01, 2.595360196832484e-03, 
               2.366307734453966e-01, 2.605305478645169e-03, 
               2.392410107900045e-01, 2.615152863467387e-03, 
               2.418610464166217e-01, 2.624901981248283e-03, 
               2.444907818747656e-01, 2.634552465780715e-03, 
               2.471301183494740e-01, 2.644103954293499e-03, 
               2.497789566650175e-01, 2.653556087937848e-03, 
               2.524371972886257e-01, 2.662908511535931e-03, 
               2.551047403342255e-01, 2.672160873649816e-03, 
               2.577814855661960e-01, 2.681312826662874e-03, 
               2.604673324031358e-01, 2.690364026606069e-03, 
               2.631621799216420e-01, 2.699314133415761e-03, 
               2.658659268600997e-01, 2.708162810774449e-03, 
               2.685784716224925e-01, 2.716909726184398e-03, 
               2.712997122822138e-01, 2.725554550969920e-03, 
               2.740295465859026e-01, 2.734096960296611e-03, 
               2.767678719572811e-01, 2.742536633172416e-03, 
               2.795145855010119e-01, 2.750873252468412e-03, 
               2.822695840065623e-01, 2.759106504927022e-03, 
               2.850327639520861e-01, 2.767236081197360e-03, 
               2.878040215083110e-01, 2.775261676110422e-03, 
               2.905832525424372e-01, 2.783182986653888e-03, 
               2.933703526220562e-01, 2.790999717992539e-03, 
               2.961652170190719e-01, 2.798711572664749e-03, 
               2.989677407136363e-01, 2.806318264576697e-03, 
               3.017778183980938e-01, 2.813819506196087e-03, 
               3.045953444809429e-01, 2.821215014200597e-03, 
               3.074202130907993e-01, 2.828504513725542e-03, 
               3.102523180803745e-01, 2.835687729504816e-03, 
               3.130915530304677e-01, 2.842764389425220e-03, 
               3.159378112539628e-01, 2.849734231650496e-03, 
               3.187909857998365e-01, 2.856596991547708e-03, 
               3.216509694571770e-01, 2.863352412508336e-03, 
               3.245176547592142e-01, 2.870000238397363e-03, 
               3.273909339873567e-01, 2.876540222855907e-03, 
               3.302706991752399e-01, 2.882972117832009e-03, 
               3.331568421127814e-01, 2.889295682847058e-03, 
               3.360492543502505e-01, 2.895510677800834e-03, 
               3.389478272023406e-01, 2.901616872891095e-03, 
               3.418524517522529e-01, 2.907614036169251e-03, 
               3.447630188557899e-01, 2.913501942921028e-03, 
               3.476794191454582e-01, 2.919280372405099e-03, 
               3.506015430345749e-01, 2.924949105464326e-03, 
               3.535292807213881e-01, 2.930507932138406e-03, 
               3.564625221932012e-01, 2.935956641504900e-03, 
               3.594011572305079e-01, 2.941295029343576e-03, 
               3.623450754111327e-01, 2.946522895553480e-03, 
               3.652941661143807e-01, 2.951640041694335e-03, 
               3.682483185251950e-01, 2.956646278489199e-03, 
               3.712074216383188e-01, 2.961541415811035e-03, 
               3.741713642624688e-01, 2.966325270229946e-03, 
               3.771400350245109e-01, 2.970997661984745e-03, 
               3.801133223736472e-01, 2.975558415912980e-03, 
               3.830911145856072e-01, 2.980007359010539e-03, 
               3.860732997668452e-01, 2.984344326553422e-03, 
               3.890597658587456e-01, 2.988569153933460e-03, 
               3.920504006418327e-01, 2.992681682816965e-03, 
               3.950450917399880e-01, 2.996681758667672e-03, 
               3.980437266246739e-01, 3.000569231563306e-03, 
               4.010461926191601e-01, 3.004343953887701e-03, 
               4.040523769027583e-01, 3.008005786118856e-03, 
               4.070621665150622e-01, 3.011554589107490e-03, 
               4.100754483601922e-01, 3.014990229897405e-03, 
               4.130921092110436e-01, 3.018312579388359e-03, 
               4.161120357135424e-01, 3.021521512740550e-03, 
               4.191351143909041e-01, 3.024616909374088e-03, 
               4.221612316478993e-01, 3.027598653251193e-03, 
               4.251902737751198e-01, 3.030466631230588e-03, 
               4.282221269532522e-01, 3.033220737198242e-03, 
               4.312566772573562e-01, 3.035860866558192e-03, 
               4.342938106611434e-01, 3.038386920385936e-03, 
               4.373334130412631e-01, 3.040798803761146e-03, 
               4.403753701815900e-01, 3.043096426054360e-03, 
               4.434195677775168e-01, 3.045279700929186e-03, 
               4.464658914402488e-01, 3.047348546348816e-03, 
               4.495142267011017e-01, 3.049302884573155e-03, 
               4.525644590158038e-01, 3.051142642166461e-03, 
               4.556164737687995e-01, 3.052867749997692e-03, 
               4.586701562775565e-01, 3.054478143244580e-03, 
               4.617253917968746e-01, 3.055973761393724e-03, 
               4.647820655231978e-01, 3.057354548247548e-03, 
               4.678400625989280e-01, 3.058620451920429e-03, 
               4.708992681167410e-01, 3.059771424844771e-03, 
               4.739595671239041e-01, 3.060807423772197e-03, 
               4.770208446265956e-01, 3.061728409774109e-03, 
               4.800829855942257e-01, 3.062534348242358e-03, 
               4.831458749637597e-01, 3.063225208893930e-03, 
               4.862093976440400e-01, 3.063800965768721e-03, 
               4.892734385201126e-01, 3.064261597232237e-03, 
               4.923378824575510e-01, 3.064607085976397e-03, 
               4.954026143067836e-01, 3.064837419018474e-03, 
               4.984675189074203e-01, 3.064952587703322e-03, 
               5.015324810925796e-01, 3.064952587703166e-03, 
               5.045973856932164e-01, 3.064837419018171e-03, 
               5.076621175424491e-01, 3.064607085976323e-03, 
               5.107265614798875e-01, 3.064261597232645e-03, 
               5.137906023559599e-01, 3.063800965768877e-03, 
               5.168541250362404e-01, 3.063225208893865e-03, 
               5.199170144057743e-01, 3.062534348316794e-03, 
               5.229791553734046e-01, 3.061728409699637e-03, 
               5.260404328760959e-01, 3.060807423773230e-03, 
               5.291007318832590e-01, 3.059771424845080e-03, 
               5.321599374010719e-01, 3.058620451919789e-03, 
               5.352179344768023e-01, 3.057354548247110e-03, 
               5.382746082031254e-01, 3.055973761529732e-03, 
               5.413298437224435e-01, 3.054478143107761e-03, 
               5.443835262312005e-01, 3.052867749998275e-03, 
               5.474355409841962e-01, 3.051142642166267e-03, 
               5.504857732988985e-01, 3.049302884573633e-03, 
               5.535341085597513e-01, 3.047348546565310e-03, 
               5.565804322224833e-01, 3.045279700712006e-03, 
               5.596246298184103e-01, 3.043096426055048e-03, 
               5.626665869587373e-01, 3.040798803760717e-03, 
               5.657061893388569e-01, 3.038386920385788e-03, 
               5.687433227426442e-01, 3.035860866558609e-03, 
               5.717778730467480e-01, 3.033220737429181e-03, 
               5.748097262248805e-01, 3.030466631272724e-03, 
               5.778387683521010e-01, 3.027598652978324e-03, 
               5.808648856090960e-01, 3.024616909373873e-03, 
               5.838879642864582e-01, 3.021521512740307e-03, 
               5.869078907889567e-01, 3.018312579704084e-03, 
               5.899245516398079e-01, 3.014990229580532e-03, 
               5.929378334849380e-01, 3.011554589109514e-03, 
               5.959476230972421e-01, 3.008005786116830e-03, 
               5.989538073808403e-01, 3.004343954274837e-03, 
               6.019562733753263e-01, 3.000569231556985e-03, 
               6.049549082600121e-01, 2.996681758286835e-03, 
               6.079495993581674e-01, 2.992681682819061e-03, 
               6.109402341412543e-01, 2.988569153933535e-03, 
               6.139267002331545e-01, 2.984344326549989e-03, 
               6.169088854143929e-01, 2.980007359854261e-03, 
               6.198866776263531e-01, 2.975558415068941e-03, 
               6.228599649754897e-01, 2.970997661986975e-03, 
               6.258286357375319e-01, 2.966325270230031e-03, 
               6.287925783616812e-01, 2.961541415811769e-03, 
               6.317516814748052e-01, 2.956646278975347e-03, 
               6.347058338856194e-01, 2.951640041704650e-03, 
               6.376549245888677e-01, 2.946522895057500e-03, 
               6.405988427694924e-01, 2.941295029342256e-03, 
               6.435374778067995e-01, 2.935956641504437e-03, 
               6.464707192786130e-01, 2.930507932676841e-03, 
               6.493984569654256e-01, 2.924949105427642e-03, 
               6.523205808545427e-01, 2.919280371903359e-03, 
               6.552369811442104e-01, 2.913501942922071e-03, 
               6.581475482477477e-01, 2.907614036169003e-03, 
               6.610521727976596e-01, 2.901616873483922e-03, 
               6.639507456497494e-01, 2.895510677823997e-03, 
               6.668431578872188e-01, 2.889295682232377e-03, 
               6.697293008247611e-01, 2.882972117833167e-03, 
               6.726090660126437e-01, 2.876540222851568e-03, 
               6.754823452407861e-01, 2.870000239623437e-03, 
               6.783490305428231e-01, 2.863352411280052e-03, 
               6.812090142001634e-01, 2.856596991551702e-03, 
               6.840621887460369e-01, 2.849734231646146e-03, 
               6.869084469695320e-01, 2.842764390106665e-03, 
               6.897476819196252e-01, 2.835687729537966e-03, 
               6.925797869092010e-01, 2.828504513007131e-03, 
               6.954046555190565e-01, 2.821215014713380e-03, 
               6.982221816019056e-01, 2.813819505693634e-03, 
               7.010322592863640e-01, 2.806318264573593e-03, 
               7.038347829809285e-01, 2.798711573986869e-03, 
               7.066296473779442e-01, 2.790999716665707e-03, 
               7.094167474575634e-01, 2.783182987050391e-03, 
               7.121959784916894e-01, 2.775261675738634e-03, 
               7.149672360479135e-01, 2.767236081175697e-03, 
               7.177304159934377e-01, 2.759106505767231e-03, 
               7.204854144989887e-01, 2.750873251623279e-03, 
               7.232321280427194e-01, 2.742536633179460e-03, 
               7.259704534140980e-01, 2.734096960297098e-03, 
               7.287002877177862e-01, 2.725554550969401e-03, 
               7.314215283775083e-01, 2.716909727094175e-03, 
               7.341340731399009e-01, 2.708162809853096e-03, 
               7.368378200783590e-01, 2.699314133418774e-03, 
               7.395326675968646e-01, 2.690364026601582e-03, 
               7.422185144338045e-01, 2.681312826648798e-03, 
               7.448952596657753e-01, 2.672160873661773e-03, 
               7.475628027113750e-01, 2.662908512333130e-03, 
               7.502210433349823e-01, 2.653556087135931e-03, 
               7.528698816505259e-01, 2.644103954298039e-03, 
               7.555092181252352e-01, 2.634552465773960e-03, 
               7.581389535833788e-01, 2.624901981290853e-03, 
               7.607589892099962e-01, 2.615152864449845e-03, 
               7.633692265546049e-01, 2.605305477648761e-03, 
               7.659695675349042e-01, 2.595360196835761e-03, 
               7.685599144404598e-01, 2.585317391740490e-03, 
               7.711401699363736e-01, 2.575177440744415e-03, 
               7.737102370669440e-01, 2.564940724859271e-03, 
               7.762700192593055e-01, 2.554607629638024e-03, 
               7.788194203270611e-01, 2.544178539752480e-03, 
               7.813583444738952e-01, 2.533653852513918e-03, 
               7.838866962971712e-01, 2.523033959756006e-03, 
               7.864043807915195e-01, 2.512319261458018e-03, 
               7.889113033524066e-01, 2.501510161365493e-03, 
               7.914073697796881e-01, 2.490607061094972e-03, 
               7.938924862811515e-01, 2.479610377180304e-03, 
               7.963665594760361e-01, 2.468520518242930e-03, 
               7.988294963985487e-01, 2.457337902166722e-03, 
               8.012812045013499e-01, 2.446062949142121e-03, 
               8.037215916590345e-01, 2.434696083892455e-03, 
               8.061505661715941e-01, 2.423237729299754e-03, 
               8.085680367678615e-01, 2.411688322303778e-03, 
               8.109739126089405e-01, 2.400048292605185e-03, 
               8.133681032916196e-01, 2.388318078679145e-03, 
               8.157505188517711e-01, 2.376498121291003e-03, 
               8.181210697677254e-01, 2.364588865693797e-03, 
               8.204796669636432e-01, 2.352590754964180e-03, 
               8.228262218128544e-01, 2.340504246604330e-03, 
               8.251606461411946e-01, 2.328329790306297e-03, 
               8.274828522303153e-01, 2.316067844673983e-03, 
               8.297927528209800e-01, 2.303718870458982e-03, 
               8.320902611163449e-01, 2.291283332872950e-03, 
               8.343752907852198e-01, 2.278761694427203e-03, 
               8.366477559653076e-01, 2.266154432810429e-03, 
               8.389075712664400e-01, 2.253462016936542e-03, 
               8.411546517737761e-01, 2.240684924966531e-03, 
               8.433889130509994e-01, 2.227823636996161e-03, 
               8.456102711434901e-01, 2.214878637609592e-03, 
               8.478186425814782e-01, 2.201850408004246e-03, 
               8.500139443831791e-01, 2.188739445594519e-03, 
               8.521960940579119e-01, 2.175546237753722e-03, 
               8.543650096092031e-01, 2.162271281581776e-03, 
               8.565206095378637e-01, 2.148915075882762e-03, 
               8.586628128450529e-01, 2.135478122532946e-03, 
               8.607915390353194e-01, 2.121960927689469e-03, 
               8.629067081196297e-01, 2.108363994270574e-03, 
               8.650082406183739e-01, 2.094687840719055e-03, 
               8.670960575643465e-01, 2.080932975882826e-03, 
               8.691700805057221e-01, 2.067099917901874e-03, 
               8.712302315089964e-01, 2.053189186556701e-03, 
               8.732764331619172e-01, 2.039201304555963e-03, 
               8.753086085763934e-01, 2.025136798848380e-03, 
               8.773266813913865e-01, 2.010996192556801e-03, 
               8.793305757757724e-01, 1.996780025104501e-03, 
               8.813202164312008e-01, 1.982488825256716e-03, 
               8.832955285949153e-01, 1.968123131402049e-03, 
               8.852564380425716e-01, 1.953683483338045e-03, 
               8.872028710910163e-01, 1.939170423644402e-03, 
               8.891347546010671e-01, 1.924584499165867e-03, 
               8.910520159802531e-01, 1.909926251971837e-03, 
               8.929545831855425e-01, 1.895196241913645e-03, 
               8.948423847260554e-01, 1.880395016406271e-03, 
               8.967153496657427e-01, 1.865523133170722e-03, 
               8.985734076260593e-01, 1.850581151020648e-03, 
               9.004164887886037e-01, 1.835569631419270e-03, 
               9.022445238977428e-01, 1.820489138437896e-03, 
               9.040574442632123e-01, 1.805340240299836e-03, 
               9.058551817627015e-01, 1.790123499990756e-03, 
               9.076376688444123e-01, 1.774839498701390e-03, 
               9.094048385295936e-01, 1.759488804430500e-03, 
               9.111566244150621e-01, 1.744071995608651e-03, 
               9.128929606756969e-01, 1.728589651523398e-03, 
               9.146137820669109e-01, 1.713042353934446e-03, 
               9.163190239271052e-01, 1.697430687051311e-03, 
               9.180086221800989e-01, 1.681755237500761e-03, 
               9.196825133375320e-01, 1.666016594300035e-03, 
               9.213406345012554e-01, 1.650215350412976e-03, 
               9.229829233656954e-01, 1.634352093304817e-03, 
               9.246093182201915e-01, 1.618427428509447e-03, 
               9.262197579513167e-01, 1.602441948063689e-03, 
               9.278141820451742e-01, 1.586396254262007e-03, 
               9.293925305896696e-01, 1.570290950020289e-03, 
               9.309547442767648e-01, 1.554126640513353e-03, 
               9.325007644047063e-01, 1.537903933127443e-03, 
               9.340305328802270e-01, 1.521623437450787e-03, 
               9.355439922207351e-01, 1.505285765236739e-03, 
               9.370410855564695e-01, 1.488891530396064e-03, 
               9.385217566326374e-01, 1.472441348953638e-03, 
               9.399859498115291e-01, 1.455935839039620e-03, 
               9.414336100746108e-01, 1.439375622607603e-03, 
               9.428646830245886e-01, 1.422761314957181e-03, 
               9.442791148874528e-01, 1.406093550878377e-03, 
               9.456768525144987e-01, 1.389372949629079e-03, 
               9.470578433843246e-01, 1.372600141305912e-03, 
               9.484220356048081e-01, 1.355775756146749e-03, 
               9.497693779150505e-01, 1.338900426348792e-03, 
               9.510998196873051e-01, 1.321974786016581e-03, 
               9.524133109288809e-01, 1.304999471146592e-03, 
               9.537098022840194e-01, 1.287975119606437e-03, 
               9.549892450357504e-01, 1.270902371102617e-03, 
               9.562515911077238e-01, 1.253781867159750e-03, 
               9.574967930660124e-01, 1.236614251101239e-03, 
               9.587248041208960e-01, 1.219400168013937e-03, 
               9.599355781286223e-01, 1.202140264733456e-03, 
               9.611290695931369e-01, 1.184835189822865e-03, 
               9.623052336677940e-01, 1.167485593536211e-03, 
               9.634640261570433e-01, 1.150092127799703e-03, 
               9.646054035180871e-01, 1.132655446195467e-03, 
               9.657293228625210e-01, 1.115176203917718e-03, 
               9.668357419579428e-01, 1.097655057765307e-03, 
               9.679246192295412e-01, 1.080092666122266e-03, 
               9.689959137616531e-01, 1.062489688912462e-03, 
               9.700495852993058e-01, 1.044846787577856e-03, 
               9.710855942497301e-01, 1.027164625070085e-03, 
               9.721039016838450e-01, 1.009443865817047e-03, 
               9.731044693377235e-01, 9.916851756939728e-04, 
               9.740872596140269e-01, 9.738892220019419e-04, 
               9.750522355834201e-01, 9.560566734382288e-04, 
               9.759993609859599e-01, 9.381882000834967e-04, 
               9.769286002324540e-01, 9.202844733636718e-04, 
               9.778399184058001e-01, 9.023461660241878e-04, 
               9.787332812623017e-01, 8.843739521207913e-04, 
               9.796086552329493e-01, 8.663685069774676e-04, 
               9.804660074246846e-01, 8.483305071631894e-04, 
               9.813053056216352e-01, 8.302606304740128e-04, 
               9.821265182863286e-01, 8.121595559088899e-04, 
               9.829296145608706e-01, 7.940279636315677e-04, 
               9.837145642681131e-01, 7.758665349520331e-04, 
               9.844813379127795e-01, 7.576759523120330e-04, 
               9.852299066825798e-01, 7.394568992348329e-04, 
               9.859602424492927e-01, 7.212100603239427e-04, 
               9.866723177698167e-01, 7.029361212198031e-04, 
               9.873661058872094e-01, 6.846357685867049e-04, 
               9.880415807316865e-01, 6.663096900798849e-04, 
               9.886987169216033e-01, 6.479585743169199e-04, 
               9.893374897644127e-01, 6.295831108668521e-04, 
               9.899578752575895e-01, 6.111839902037773e-04, 
               9.905598500895291e-01, 5.927619036949534e-04, 
               9.911433916404307e-01, 5.743175435699768e-04, 
               9.917084779831419e-01, 5.558516028961642e-04, 
               9.922550878839893e-01, 5.373647755515191e-04, 
               9.927832008035694e-01, 5.188577562008609e-04, 
               9.932927968975250e-01, 5.003312402692803e-04, 
               9.937838570172919e-01, 4.817859239114471e-04, 
               9.942563627108174e-01, 4.632225039900671e-04, 
               9.947102962232587e-01, 4.446416780521559e-04, 
               9.951456404976434e-01, 4.260441442988453e-04, 
               9.955623791755239e-01, 4.074306015659492e-04, 
               9.959604965975856e-01, 3.888017492843920e-04, 
               9.963399778042428e-01, 3.701582874722940e-04, 
               9.967008085362071e-01, 3.515009167036271e-04, 
               9.970429752350274e-01, 3.328303380812539e-04, 
               9.973664650436136e-01, 3.141472532134656e-04, 
               9.976712658067317e-01, 2.954523642010730e-04, 
               9.979573660714878e-01, 2.767463736200558e-04, 
               9.982247550877872e-01, 2.580299844998542e-04, 
               9.984734228088017e-01, 2.393039003326961e-04, 
               9.987033598914243e-01, 2.205688250902763e-04, 
               9.989145576967806e-01, 2.018254632684662e-04, 
               9.991070082908062e-01, 1.830745200184704e-04, 
               9.992807044450196e-01, 1.643167014285894e-04, 
               9.994356396377237e-01, 1.455527151255845e-04, 
               9.995718080561888e-01, 1.267832717850644e-04, 
               9.996892046012996e-01, 1.080090889880246e-04, 
               9.997878248991550e-01, 8.923090277268586e-05, 
               9.998676653355210e-01, 7.044950869281056e-05, 
               9.999287231849898e-01, 5.166595174600893e-05, 
               9.999709973034228e-01, 3.288286582916133e-05, 
               9.999944954921908e-01, 1.412631868620769e-05; 
               
       return aw.transpose();
       } 
   }; 
/*************************************************/
} 
#endif 
